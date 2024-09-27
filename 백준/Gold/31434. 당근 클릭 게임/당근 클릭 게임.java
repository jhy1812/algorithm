import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();
        int carrot = 0;
        int sec = 0;
        int[] cost = new int[N + 1];
        int[] speed = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            int tmp = sc.nextInt();
            cost[i] = tmp;
        }

        for (int i = 1; i <= N; i++) {
            int tmp = sc.nextInt();
            speed[i] = tmp;
        }

        int[][] dp = new int[K + 1][N + 1];
        int[][] s = new int[K + 1][N + 1];
        dp[1][0] = 1;
        s[1][0] = 1;
        carrot = K;
        for (int i = 2; i <= K; i++) {
            for (int j = 0; j <= N; j++) {
                for (int k = 0; k <= N; k++) {
                    if (cost[j] <= dp[i - 1][k]) {
                        if (dp[i - 1][k] + (K - i) * s[i - 1][k] <= dp[i - 1][k] - cost[j] + (K - i) * (s[i - 1][k] + speed[j])) {
                            s[i][j] = s[i - 1][k] + speed[j];
                            dp[i][j] = dp[i - 1][k] - cost[j];
                            carrot = Math.max(carrot, dp[i - 1][k] - cost[j] + (K - i) * (s[i - 1][k] + speed[j]));
                        }
                    }
                }
            }
        }

        System.out.print(carrot);
    }
}