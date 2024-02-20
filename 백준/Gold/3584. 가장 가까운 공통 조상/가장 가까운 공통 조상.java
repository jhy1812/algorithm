import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int result;
    public static int[] lev;
    public static int[] par;
    public static List<List<Integer>> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());

        for (int tc = 1; tc <= T; tc++) {
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
                par[b] = a;
                arr.get(a).add(b);
            }

            for (int i = 1; i <= N; i++) {
                if (par[i] == 0) {
                    dfs(0, i);
                }
            }

            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            LCA(a, b);

            System.out.println(result);
        }
    }

    private static void dfs(int lv, int node) {
        lev[node] = lv;

        for (int i = 0; i < arr.get(node).size(); i++) {
            dfs(lv + 1, arr.get(node).get(i));
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