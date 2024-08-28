import java.io.*;
import java.util.*;

public class Main {

    public static int N, K, result;
    public static int[][] dp;
    public static List<List<Integer>> arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        result = 0;
        dp = new int[N+1][K+1];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
            if(i == 0) continue;
            Arrays.fill(dp[i], 1);
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
        int st = K+1;
        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs(child, cur);
            for (int i = 1; i <= K; i++) {
                if (dp[child][i-1] == 0) {
                    st = i;
                    break;
                }
                dp[cur][i] += dp[child][i-1];
            }
        }

        if (st != K+1) {
            for (int i = st; i <= K; i++) {
                dp[cur][i] += dp[cur][i-1];
            }
        }

    }

    public static void dfs2(int cur, int par) {
        for (int i = K; i >= 1; i--) {
            dp[cur][i] += dp[par][i-1];
            if (i > 1 && par != 0) {
                dp[cur][i] -= dp[cur][i-2];
            }
        }


        result = Math.max(result, dp[cur][K]);

        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs2(child, cur);
        }
    }
}