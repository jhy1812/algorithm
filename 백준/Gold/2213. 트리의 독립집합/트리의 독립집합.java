import java.io.*;
import java.util.*;

public class Main {

    public static int n;
    public static int[] weight;
    public static int[][] dp;
    public static PriorityQueue<Integer> result;
    public static List<List<Integer>> arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        weight = new int[n+1];
        dp = new int[n+1][2];
        result = new PriorityQueue<>();
        arr = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            arr.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= n; i++) {
            dp[i][0] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr.get(u).add(v);
            arr.get(v).add(u);
        }

        dfs(1, 0);
        dfs2(1, 0, false);

        bw.write(Math.max(dp[1][0], dp[1][1]) + "\n");

        while (!result.isEmpty()) {
            bw.write(result.poll() + " ");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs(int cur, int par) {

        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs(child, cur);
            dp[cur][0] += dp[child][1];
            dp[cur][1] += Math.max(dp[child][0], dp[child][1]);
        }
    }

    public static void dfs2(int cur, int par, boolean check) {
        boolean nextCheck = false;

        if (!check) {
            if (dp[cur][0] >= dp[cur][1]) {
                nextCheck = true;
                result.add(cur);
            }
        }

        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs2(child, cur, nextCheck);
        }
    }
}