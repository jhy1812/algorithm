import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        long[][] dp = new long[65][11];

        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        dp[1][10] = 10;

        for (int i = 2; i <= 64; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
            }

            for (int j = 0; j < 10; j++) {
                dp[i][10] += dp[i][j];
            }
        }

        int T = Integer.parseInt(bf.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int n = Integer.parseInt(bf.readLine());

            System.out.println(dp[n][10]);
        }
    }
}