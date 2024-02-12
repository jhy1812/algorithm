import java.util.Scanner;

public class Main {
    public static long MOD = 1000000007L;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long[] dp = new long[5002];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < 5002; i++) {
            long tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp += dp[j] * dp[i - j - 1];
                tmp %= MOD;
            }
            dp[i] = tmp % MOD;
        }

        int T = sc.nextInt();

        for (int tc = 0; tc < T; tc++) {
            int N = sc.nextInt();
            System.out.println(dp[N + 1]);
        }
    }
}
