import java.io.*;
import java.util.*;

public class Main {

    public static int MOD = 1000000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int sign = 0;

        int[] dp = new int[3];
        dp[1] = 1;

        for (int i = 2; i <= Math.abs(n); i++) {
            dp[i%3] = (dp[(i+1)%3] + dp[(i+2)%3]) % MOD;
        }

        if (n < 0 && Math.abs(n)%2 == 0) {
            sign = -1;
        }
        else if (n != 0) {
            sign = 1;
        }

        System.out.print(sign + "\n" + dp[Math.abs(n)%3]);
    }
}