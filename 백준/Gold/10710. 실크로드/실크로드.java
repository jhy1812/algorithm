import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] dis = new int[N + 1];
        int[] wt = new int[M + 1];
        int[][] dp = new int[M + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            int tmp = Integer.parseInt(bf.readLine());
            dis[i] = tmp;
        }

        for (int i = 1; i <= M; i++) {
            int tmp = Integer.parseInt(bf.readLine());
            wt[i] = tmp;
        }

        for (int j = 1; j <= N; j++) {
            dp[0][j] = 1000000000;
        }

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i - 1][j - 1] + dis[j] * wt[i]);
            }
        }

        System.out.print(dp[M][N]);
    }
}