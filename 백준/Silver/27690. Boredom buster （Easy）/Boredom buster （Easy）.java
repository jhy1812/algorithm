import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long[] dp = new long[1000001];

        for (int i = 1; i <= 1000000; i++) {
            if (i%3 == 0) {
                dp[i] = (long) (i/3) * (2*i/3) + dp[i/3] + dp[2*i/3];
            }
            else if (i%2 == 0) {
                dp[i] = (long) (i / 2) * (i/2) + 2*dp[i/2];
            }
            else {
                dp[i] = (long) i - 1 + dp[i - 1];
            }
        }

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            String space = br.readLine();
            int n = Integer.parseInt(br.readLine());
            System.out.println(dp[n]);
        }
    }
}