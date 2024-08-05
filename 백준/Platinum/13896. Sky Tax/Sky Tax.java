import java.io.*;
import java.util.*;

public class Main {

    public static int N, Q, R, cap;
    public static int[] tax, lev;
    public static int[][] par;
    public static List<List<Integer>> arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            bw.write("Case #" + tc + ":\n");
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            Q = Integer.parseInt(st.nextToken());
            R = Integer.parseInt(st.nextToken());
            cap = R;
            tax = new int[N+1];
            lev = new int[N+1];
            par = new int[N+1][20];
            arr = new ArrayList<>();

            for (int i = 0; i <= N; i++) {
                arr.add(new ArrayList<>());
            }

            for (int i = 1; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                arr.get(u).add(v);
                arr.get(v).add(u);
            }

            dfs(1, R, 0);

            for (int i = 0; i < Q; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int U = Integer.parseInt(st.nextToken());

                if (S == 0) {
                    cap = U;
                }
                else {
                    if (cap == U) {
                        bw.write(tax[R] + "\n");
                    }
                    else {
                        int lca = LCA(cap, U);
                        if (lca == U) {
                            int city = sol(cap, U);
                            int ret = tax[R] - tax[city];
                            bw.write(ret + "\n");
                        }
                        else {
                            bw.write(tax[U] + "\n");
                        }
                    }
                }
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }

    public static int dfs(int lv, int cur, int parent) {
        tax[cur]++;
        lev[cur] = lv;
        par[cur][0] = parent;

        for (int i = 1; i < 20; i++) {
            par[cur][i] = par[par[cur][i-1]][i-1];
        }

        for (int child : arr.get(cur)) {
            if (child == parent) continue;
            tax[cur] += dfs(lv + 1, child, cur);
        }

        return tax[cur];
    }

    public static int LCA(int a, int b) {
        if (lev[a] < lev[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        if (lev[a] != lev[b]) {
            for (int i = 19; i >=0; i--) {
                if (lev[par[a][i]] >= lev[b]) {
                    a = par[a][i];
                }
            }
        }

        if (a != b) {
            for (int i = 19; i >= 0; i--) {
                if (par[a][i] != par[b][i]) {
                    a = par[a][i];
                    b = par[b][i];
                }
            }
        }

        if (a != b) {
            return par[a][0];
        }
        else {
            return a;
        }
    }

    public static int sol(int capital, int city) {
        for (int i = 19; i >= 0; i--) {
            if (lev[par[capital][i]] > lev[city]) {
                capital = par[capital][i];
            }
        }

        return capital;
    }
}