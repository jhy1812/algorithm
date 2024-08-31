import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int K = Integer.parseInt(br.readLine());
        long[][] dp = new long[K+1][2];

        dp[0][0] = 1;

        for (int i = 1; i <= K; i++) {
            dp[i][0] += dp[i-1][1];
            dp[i][1] += dp[i-1][0] + dp[i-1][1];
        }

        System.out.print(dp[K][0] + " " + dp[K][1]);
    }
}