import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, result;
    public static int[] lev;
    public static int[] len;
    public static int[][] par;
    public static List<List<Integer>> arr;
    public static List<List<Integer>> lst;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer fir = new StringTokenizer(bf.readLine());
        N = Integer.parseInt(fir.nextToken());
        M = Integer.parseInt(fir.nextToken());

        lev = new int[N + 1];
        len = new int[N + 1];
        par = new int[N + 1][20];
        arr = new ArrayList<>();
        lst = new ArrayList<>();
        int[] check = new int[N + 1];

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<Integer>());
            lst.add(new ArrayList<Integer>());
        }

        for (int i = 1; i < N; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            arr.get(a).add(b);
            arr.get(b).add(a);
            lst.get(a).add(c);
            lst.get(b).add(c);
            check[a]++;
            check[b]++;
        }

        for (int i = 1; i <= N; i++) {
            if (check[i] == 1) {
                dfs(0, i, 0, 0);
                break;
            }
        }


        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            LCA(a, b);
            System.out.println(len[a] + len[b] - 2 * len[result]);
        }
    }

    private static void dfs(int lv, int node, int parent, int dis) {
        lev[node] = lv;
        len[node] = dis;
        par[node][0] = parent;
        int tmp = parent;

        for (int j = 1; j < 20; j++) {
            par[node][j] = par[tmp][0];
            if (par[tmp][j - 1] == 0) {
                break;
            }
            tmp = par[tmp][j];
        }

        for (int i = 0; i < arr.get(node).size(); i++) {
            int child = arr.get(node).get(i);

            if(child == parent) continue;

            dfs(lv + 1, child, node, dis + lst.get(node).get(i));
        }
    }

    private static void LCA(int a, int b) {
        if (lev[a] < lev[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        if (lev[a] != lev[b]) {
            for (int i = 19; i >= 0; i--) {
                if (lev[par[a][i]] >= lev[b]) {
                    if (par[a][i] != 0) a = par[a][i];
                }
            }
        }

        if (a != b) {
            for (int i = 19; i >= 0; i--) {
                if (par[a][i] != par[b][i]) {
                    a = par[a][i];
                    b = par[b][i];
                }
                result = par[a][i];
            }
        }
        else {
            result = a;
        }
    }
}