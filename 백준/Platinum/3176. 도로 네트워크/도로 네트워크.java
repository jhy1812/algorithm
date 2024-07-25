import java.io.*;
import java.util.*;

public class Main {

    static private int N, K, mx, mn;
    static private int[] lev;
    static private int[][] par, max, min;
    static private List<List<Node>> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        lev = new int[N + 1];
        par = new int[N + 1][20];
        max = new int[N + 1][20];
        min = new int[N + 1][20];

        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
            Arrays.fill(max[i], -Integer.MAX_VALUE);
            Arrays.fill(min[i], Integer.MAX_VALUE);
        }

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            arr.get(s).add(new Node(e, c));
            arr.get(e).add(new Node(s, c));
        }

        dfs(0, 1, 0, 0);

        K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            mx = -Integer.MAX_VALUE;
            mn = Integer.MAX_VALUE;
            solve(s, e);

            bw.write(mn + " " + mx + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }

    static private void dfs(int lv, int cur, int parent, int dis) {
        lev[cur] = lv;
        if (lv != 0) {
            max[cur][0] = dis;
            min[cur][0] = dis;
        }
        par[cur][0] = parent;
        int tmp = parent;
        for (int i = 1; i < 20; i++) {
            par[cur][i] = par[par[cur][i - 1]][i - 1];
            max[cur][i] = Math.max(max[cur][i - 1], max[par[cur][i - 1]][i - 1]);
            min[cur][i] = Math.min(min[cur][i - 1], min[par[cur][i - 1]][i - 1]);
        }

        for (Node node : arr.get(cur)) {
            int child = node.getE();
            int d = node.getCost();
            if (child == parent) continue;

            dfs(lv + 1, child, cur, d);
        }
    }

    static private void solve(int a, int b) {
        if (lev[a] < lev[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        if (lev[a] != lev[b]) {
            for (int i = 19; i >= 0; i--) {
                if (lev[par[a][i]] >= lev[b]) {
                    if (par[a][i] != 0) {
                        mx = Math.max(mx, max[a][i]);
                        mn = Math.min(mn, min[a][i]);
                        a = par[a][i];
                    }
                }
            }
        }

        if (a != b) {
            for (int i = 19; i >= 0; i--) {
                if (par[a][i] != par[b][i]) {
                    mx = Math.max(mx, max[a][i]);
                    mx = Math.max(mx, max[b][i]);
                    mn = Math.min(mn, min[a][i]);
                    mn = Math.min(mn, min[b][i]);
                    a = par[a][i];
                    b = par[b][i];
                }
            }
        }

        if (a != b) {
            mx = Math.max(mx, max[a][0]);
            mx = Math.max(mx, max[b][0]);
            mn = Math.min(mn, min[a][0]);
            mn = Math.min(mn, min[b][0]);
        }
    }
}

class Node {
    private int e;
    private int cost;

    public Node(int e, int cost) {
        this.e = e;
        this.cost = cost;
    }

    public int getE() {
        return this.e;
    }

    public int getCost() {
        return this.cost;
    }
}