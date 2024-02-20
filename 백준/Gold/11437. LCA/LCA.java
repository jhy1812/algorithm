import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int M;
    public static int result;
    public static int[] lev;
    public static int[] par;
    public static List<List<Integer>> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());

        lev = new int[N + 1];
        par = new int[N + 1];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < N - 1; i++) {
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
        par[node] = parent;

        for (int i = 0; i < arr.get(node).size(); i++) {
            int child = arr.get(node).get(i);
            if (parent == child) {
                continue;
            }
            dfs(lv + 1, child, node);
        }
    }

    private static void LCA(int a, int b) {
        if (lev[a] < lev[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        while (lev[a] > lev[b]) {
            a = par[a];
        }

        while (a != b) {
            a = par[a];
            b = par[b];
        }

        result = a;
    }
}