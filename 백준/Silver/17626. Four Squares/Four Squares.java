import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        long[] dp = new long[n+1];

        Arrays.fill(dp, 5L);

        for (int i = 1; i*i <= n; i++) {
            dp[i*i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                dp[i] = Math.min(dp[i], dp[i-j*j]+1);
            }
        }

        System.out.print(dp[n]);
    }
}