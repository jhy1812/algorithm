import java.io.*;
import java.util.*;

public class Main {
    public static long MOD = 1000000007L;
    public static long result = 0L;
    public static int N, K;
    public static long dp[][];
    public static List<List<Integer>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        dp = new long[N+1][N+1];
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

        System.out.print(result);
    }

    public static void dfs(int cur, int par) {
        dp[cur][1]++;

        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs(child, cur);
            for (int i = N; i >= 1; i--) {
                if (dp[cur][i] == 0L) continue;
                for (int j = 1; j <= N; j++) {
                    if (dp[child][j] == 0L) break;
                    dp[cur][i+j] += dp[cur][i] * dp[child][j];
                    dp[cur][i+j] %= MOD;
                }
            }
        }

        result += dp[cur][K];
        result %= MOD;
    }
}