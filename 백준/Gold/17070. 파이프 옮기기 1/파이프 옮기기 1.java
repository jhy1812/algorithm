import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[][] house = new int[N][N];
        long[][][] dp = new long[N][N][3];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < N; j++) {
                house[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[0][1][0] = 1L;

        for (int i = 0; i < N; i++) {
            for (int j = 2; j < N; j++) {
                if (house[i][j] == 1) continue;

                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1];
                dp[i][j][2] = dp[Math.max(0, i-1)][j][1] + dp[Math.max(0, i-1)][j][2];


                if (i >= 1) {
                    if (house[i-1][j-1] != 1 && house[i-1][j] != 1 && house[i][j-1] != 1) {
                        dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
                    }
                }
            }
        }

        System.out.print(dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2]);
    }
}