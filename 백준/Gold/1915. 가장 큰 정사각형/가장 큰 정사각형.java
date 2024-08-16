import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {1, 1, 0};
    public static int[] dx = {0, 1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][m];
        int result = 0;

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                dp[i][j] = Integer.parseInt(String.valueOf(s.charAt(j)));
                result = Math.max(result, dp[i][j]);
            }
        }

        for (int i = n-2; i >= 0; i--) {
            for (int j = m-2; j >= 0; j--) {
                if (dp[i][j] == 1) {
                    int check = Math.min(Math.min(dp[i+1][j], dp[i+1][j+1]), dp[i][j+1]);
                    dp[i][j] = check + 1;
                    result = Math.max(result, dp[i][j]);
                }
            }
        }

        System.out.print(result*result);
    }
}