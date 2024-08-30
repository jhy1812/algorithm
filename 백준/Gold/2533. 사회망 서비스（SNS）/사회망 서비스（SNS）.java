import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int[][] dp;
    public static List<List<Integer>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        dp = new int[N+1][2];
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

        dfs(1, 0);

        System.out.print(Math.min(dp[1][0], dp[1][1]));
    }

    public static void dfs(int cur, int par) {
        dp[cur][1]++;

        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs(child, cur);
            dp[cur][1] += Math.min(dp[child][0], dp[child][1]);
            dp[cur][0] += dp[child][1];
        }
    }
}