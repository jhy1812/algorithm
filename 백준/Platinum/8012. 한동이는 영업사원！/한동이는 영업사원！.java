import java.io.*;
import java.util.*;

public class Main {

    public static int n, m, de, ar, lca, result;
    public static int[] lev;
    public static int[][] par;
    public static List<List<Integer>> arr;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(bf.readLine());

        result = 0;
        lev = new int[n + 1];
        par = new int[n + 1][20];
        arr = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 1; i < n; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr.get(a).add(b);
            arr.get(b).add(a);
        }

        make_tree(0, 1, 0);

        m = Integer.parseInt(bf.readLine());

        de = Integer.parseInt(bf.readLine());

        for (int i = 1; i < m; i++) {
            ar = Integer.parseInt(bf.readLine());
            LCA(de, ar);
            result += lev[de] + lev[ar] - 2 * lev[lca];
            de = ar;
        }
        System.out.print(result);
    }

    private static void make_tree(int lv, int node, int parent) {
        lev[node] = lv;
        par[node][0] = parent;
        int tmp = parent;

        for (int i = 1; i < 20; i++) {
            par[node][i] = par[tmp][0];
            tmp = par[tmp][i];
        }

        for (int i = 0; i < arr.get(node).size(); i++) {
            int child = arr.get(node).get(i);
            if (child == parent) continue;

            make_tree(lv + 1, child, node);
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
                if (lev[par[a][i]] >= lev[b]) a = par[a][i];
            }
        }

        if (a != b) {
            for (int i = 19; i >= 0; i--) {
                if (par[a][i] != par[b][i]) {
                    a = par[a][i];
                    b = par[b][i];
                }
                lca = par[a][i];
            }
        }
        else {
            lca = a;
        }
    }
}