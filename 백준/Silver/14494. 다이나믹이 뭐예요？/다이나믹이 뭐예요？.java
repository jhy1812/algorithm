import java.io.*;
import java.util.*;

public class Main {

    public static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 0; i < m; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] += dp[i-1][j-1]%MOD;
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j]%MOD;
                dp[i][j] %= MOD;
                dp[i][j] += dp[i][j-1]%MOD;
                dp[i][j] %= MOD;
            }
        }

        System.out.print(dp[n-1][m-1]);
    }
}