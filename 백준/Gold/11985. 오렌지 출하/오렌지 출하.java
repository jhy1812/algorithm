import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] orange = new int[N+1];

        long[][] dp = new long[N+1][M+1];
        int[][] max = new int[N+1][M+1];
        int[][] min = new int[N+1][M+1];

        long result = Long.MAX_VALUE;

        for (int i = 1; i <= N; i++) {
            orange[i] = Integer.parseInt(br.readLine());
        }

        dp[1][1] = K;
        max[1][1] = orange[1];
        min[1][1] = orange[1];

        for (int i = 2; i <= N; i++) {
            dp[i][1] = dp[i-1][1];
            max[i][1] = orange[i];
            min[i][1] = orange[i];

            for (int j = 2; j <= Math.min(i, M); j++) {

                if (max[i-1][j-1] < orange[i]) {
                    dp[i][j] = dp[i-1][j-1] + (long) (orange[i] - max[i-1][j-1]) *(j-1) + orange[i] - min[i-1][j-1];
                    max[i][j] = orange[i];
                    min[i][j] = min[i-1][j-1];
                }
                else if (min[i-1][j-1] > orange[i]) {
                    dp[i][j] = dp[i-1][j-1] + (long) (min[i-1][j-1] - orange[i]) *(j-1) + max[i-1][j-1] - orange[i];
                    max[i][j] = max[i-1][j-1];
                    min[i][j] = orange[i];
                }
                else {
                    dp[i][j] = dp[i-1][j-1] + max[i-1][j-1] - min[i-1][j-1];
                    max[i][j] = max[i-1][j-1];
                    min[i][j] = min[i-1][j-1];
                }

                if (dp[i-1][j] == 0L) continue;

                dp[i][1] = Math.min(dp[i][1], dp[i-1][j]);

            }

            dp[i][1] += K;
        }

        for (int i = 1; i <= M; i++) {
            if (dp[N][i] == 0) break;
            result = Math.min(result, dp[N][i]);
        }

        System.out.print(result);
    }
}