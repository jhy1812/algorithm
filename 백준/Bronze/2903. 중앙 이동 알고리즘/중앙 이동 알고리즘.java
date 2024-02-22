import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long[] dp = new long[N + 1];
        dp[0] = 2;

        for (int i = 1; i <= N; i++) {
            dp[i] = 2 * dp[i - 1] - 1;
        }

        System.out.print(dp[N] * dp[N]);
    }
}