import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, result;
    public static int[] lev;
    public static int[][] par;
    public static List<List<Integer>> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());

        lev = new int[N + 1];
        par = new int[N + 1][20];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<Integer>());
        }

        for (int i = 1; i < N; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr.get(a).add(b);
            arr.get(b).add(a);
        }

        dfs(0, 1, 0);

        M = Integer.parseInt(bf.readLine());

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            LCA(a, b);
            System.out.println(result);
        }
    }

    private static void dfs(int lv, int node, int parent) {
        lev[node] = lv;
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

            dfs(lv + 1, child, node);
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