import java.io.*;
import java.util.*;

public class Main {

    static private int N;
    static private int[] lev, can;
    static private boolean[] check;
    static private int[][] par;
    static private int[][][] sto;
    static private List<List<Integer>> arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        lev = new int[N + 1];
        can = new int[N + 1];
        check = new boolean[6];
        par = new int[N + 1][20];
        sto = new int[N + 1][20][6];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }
        Arrays.fill(check, false);
        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            can[i] = tmp;
            check[tmp] = true;
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr.get(u).add(v);
            arr.get(v).add(u);
        }

        dfs(0, 1, 0);

        int M = Integer.parseInt(br.readLine());
        int[] num = new int[2];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            num[i%2] = Integer.parseInt(st.nextToken());
            int candy = Integer.parseInt(st.nextToken());

            if (i == 0) {
                if (check[candy]) {
                    bw.write("PLAY\n");
                }
                else {
                    bw.write("CRY\n");
                }
                continue;
            }

            if (check[candy]) {
                if (can[num[i%2]] == candy || can[num[(i + 1)%2]] == candy) {
                    bw.write("PLAY\n");
                    continue;
                }
                if (num[i%2] == num[(i + 1)%2]) {
                    if (can[num[i%2]] != candy) {
                        bw.write("CRY\n");
                        continue;
                    }
                }
                if (solve(num[i%2], num[(i + 1)%2], candy)) {
                    bw.write("PLAY\n");
                }
                else {
                    bw.write("CRY\n");
                }
            }
            else {
                bw.write("CRY\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }

    static private void dfs(int lv, int cur, int parent) {
        lev[cur] = lv;
        par[cur][0] = parent;
        if (lv != 0) {
            sto[cur][0][can[parent]] = 1;
        }
        sto[cur][0][can[cur]] = 1;
        for (int i = 1; i < 20; i++) {
            par[cur][i] = par[par[cur][i - 1]][i - 1];
            for (int j = 1; j <= 5; j++) {
                if (sto[par[cur][i - 1]][i - 1][j] == 1) {
                    sto[cur][i][j] = sto[par[cur][i - 1]][i - 1][j];
                }
                if (sto[cur][i - 1][j] == 1) {
                    sto[cur][i][j] = sto[cur][i - 1][j];
                }
            }
        }

        for (int child : arr.get(cur)) {
            if (child == parent) continue;

            dfs(lv + 1, child, cur);
        }
    }

    static private boolean solve(int a, int b, int candy) {
        if (lev[a] < lev[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        if (lev[a] != lev[b]) {
            for (int i = 19; i >= 0; i--) {
                if (lev[par[a][i]] >= lev[b]) {
                    if (sto[a][i][candy] == 1) {
                        return true;
                    }
                    a = par[a][i];
                }
            }
        }

        if (a != b) {
            for (int i = 19; i >= 0; i--) {
                if (par[a][i] != par[b][i]) {
                    if (sto[a][i][candy] == 1 || sto[b][i][candy] == 1) {
                        return true;
                    }
                    a = par[a][i];
                    b = par[b][i];
                }
            }
        }

        if (a != b) {
            if (sto[a][0][candy] == 1 || sto[b][0][candy] == 1) {
                return true;
            }
        }

        return false;
    }
}