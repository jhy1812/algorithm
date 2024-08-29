import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static long result = 0L;
    public static int[] dp;
    public static List<List<Integer>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        dp = new int[N+1];
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
        dfs2(1, 0);

        System.out.print(result);
    }

    public static void dfs(int cur, int par) {
        dp[cur]++;
        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs(child, cur);
            dp[cur] += dp[child];
        }
    }

    public static void dfs2(int cur, int par) {
        for (int child : arr.get(cur)) {
            if (child == par) continue;
            result += (long) dp[child] * (N - 1) - (long) dp[child] * (dp[child] - 1) / 2;
            dfs2(child, cur);
        }
    }
}