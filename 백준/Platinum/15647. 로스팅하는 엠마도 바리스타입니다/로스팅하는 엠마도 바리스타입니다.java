import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int[] node;
    public static long[] dp;
    public static List<List<Pair>> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        node = new int[N + 1];
        dp = new long[N + 1];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            arr.get(u).add(new Pair(v, d));
            arr.get(v).add(new Pair(u, d));
        }

        dfs(1, 0);
        dfs2(1, 0);

        for (int i = 1; i <= N; i++) {
            bw.write(dp[i] + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs(int cur, int par) {
        node[cur]++;
        for (Pair p : arr.get(cur)) {
            int child = p.getV();
            int dis = p.getD();
            if (child == par) continue;
            dfs(child, cur);
            node[cur] += node[child];
            dp[cur] += (long) dis * node[child] + dp[child];
        }
    }

    public static void dfs2(int cur, int par) {
        for (Pair p : arr.get(cur)) {
            int child = p.getV();
            int dis = p.getD();
            if (child == par) continue;
            long tmp = dp[child];
            dp[child] = dp[cur] - (long) dis * node[child] + (long) dis * (N - node[child]);
            dfs2(child, cur);
        }
    }
}

class Pair {
    private int v;
    private int d;

    public Pair(int v, int d) {
        this.v = v;
        this.d = d;
    }

    public int getV() { return this.v; }

    public int getD() {
        return this.d;
    }
}