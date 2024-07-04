import java.io.*;
import java.util.*;

public class Main {

    static public int mod = 10;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bf.readLine());
        int[][] dp = new int[2][2];

        dp[1][0] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i % 2][0] = (dp[(i - 1) % 2][0] + dp[(i - 1) % 2][1]) % mod;
            dp[i % 2][1] = dp[(i - 1) % 2][0] % mod;
        }

        System.out.print((dp[n % 2][0] + dp[n % 2][1]) % mod);
    }
}