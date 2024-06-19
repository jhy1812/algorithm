import java.io.*;
import java.util.*;

public class Main {

    static private long MOD = 1000000007L;

    public static void main(String[] args) throws IOException {
        long[][] dp = new long[5001][2];
        dp[2][1] = 1;

        for (int i = 4; i <= 5000; i += 2) {
            dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
            for (int j = 2; j <= i - 4; j += 2) {
                dp[i][0] += (dp[i - j][0] * dp[j][1]) % MOD;
                dp[i][0] %= MOD;
            }
            dp[i][0] += (dp[i - 2][0] + dp[i - 2][1]) % MOD;
            dp[i][0] %= MOD;
        }

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int L = Integer.parseInt(bf.readLine());
            System.out.println((dp[L][0] + dp[L][1]) % MOD);
        }
    }
}