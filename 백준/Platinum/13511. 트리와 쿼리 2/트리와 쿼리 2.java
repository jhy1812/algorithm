import java.io.*;
import java.util.*;

public class Main {
    public static int N, M, result;
    public static int[] lev;
    public static long[] len;
    public static int[][] par;
    public static List<List<Integer>> arr;
    public static List<List<Long>> lst;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());

        lev = new int[N + 1];
        len = new long[N + 1];
        par = new int[N + 1][20];
        arr = new ArrayList<>();
        lst = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<Integer>());
            lst.add(new ArrayList<Long>());
        }

        for (int i = 1; i < N; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            arr.get(a).add(b);
            arr.get(b).add(a);
            lst.get(a).add(c);
            lst.get(b).add(c);
        }

        M = Integer.parseInt(bf.readLine());


        make_tree(0, 1, 0, 0);

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (a == 1) {
                query(b, c, a, 0);
                System.out.println(len[b] + len[c] - 2 * len[result]);
            }
            else {
                int d = Integer.parseInt(st.nextToken());
                query(b, c, a, d);
                System.out.println(result);
            }
        }
    }

    private static void make_tree(int lv, int node, int parent, long dis) {
        lev[node] = lv;
        len[node] = dis;
        par[node][0] = parent;
        int tmp = parent;
        for (int i = 1; i <20; i++) {
            par[node][i] = par[tmp][0];
            tmp = par[tmp][i];
        }

        for (int i = 0; i < arr.get(node).size(); i++) {
            int child = arr.get(node).get(i);
            if (parent == child) continue;
            make_tree(lv + 1, child, node, dis + lst.get(node).get(i));
        }
    }

    private static void query(int a, int b, int q, int k) {
        int aa = a;
        int bb = b;

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
        if (q == 1) return;

        if (lev[aa] - lev[result] + 1 >= k) {
            k = lev[aa] - k + 1;
            if (lev[aa] != k) {
                for (int i = 19; i >= 0; i--) {
                    if (lev[par[aa][i]] >= k) {
                        if (par[aa][i] != 0) aa = par[aa][i];
                    }
                }
            }
            result = aa;
        }
        else {
            k -= (lev[aa] - lev[result] + 1);
            k += lev[result];
            if (lev[bb] != k) {
                for (int i = 19; i >= 0; i--) {
                    if (lev[par[bb][i]] >= k) {
                        if (par[bb][i] != 0) bb = par[bb][i];
                    }
                }
            }
            result = bb;
        }
    }
}