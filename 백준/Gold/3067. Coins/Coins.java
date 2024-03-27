import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int N = Integer.parseInt(bf.readLine());

            StringTokenizer st = new StringTokenizer(bf.readLine());

            int M = Integer.parseInt(bf.readLine());

            int[] dp = new int[M + 1];
            dp[0] = 1;
            for (int i = 0; i < N; i++) {
                int coin = Integer.parseInt(st.nextToken());

                for (int j = 1; j <= M; j++) {
                    if (j - coin >= 0) {
                        dp[j] += dp[j - coin];
                    }
                }
            }

            System.out.println(dp[M]);
        }
    }
}