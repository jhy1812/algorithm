import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int result = Integer.MAX_VALUE;
        int[][] dp = new int[N][10];

        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE/10);
        }

        String aft = br.readLine();
        String bef = br.readLine();

        int a = Integer.parseInt(String.valueOf(aft.charAt(0)));
        int b = Integer.parseInt(String.valueOf(bef.charAt(0)));

        if (a < b) {
            dp[0][b-a] = b-a;
            dp[0][0] = 10-(b-a);
        }
        else if (a > b) {
            dp[0][10-(a-b)] = 10-(a-b);
            dp[0][0] = a-b;
        }
        else {
            dp[0][0] = 0;
        }

        for (int i = 1; i < N; i++) {
            a = Integer.parseInt(String.valueOf(aft.charAt(i)));
            b = Integer.parseInt(String.valueOf(bef.charAt(i)));
            for (int j = 0; j < 10; j++) {

                if (j > 0) a++;
                a %= 10;

                if (a < b) {
                    dp[i][(j+b-a)%10] = Math.min(dp[i][(j+b-a)%10], dp[i-1][j]+b-a);
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j]+10-(b-a));
                }
                else if (a > b) {
                    dp[i][(j+10-(a-b))%10] = Math.min(dp[i][(j+10-(a-b))%10], dp[i-1][j]+10-(a-b));
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j]+a-b);
                }
                else {
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j]);
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            result = Math.min(result, dp[N-1][i]);
        }

        System.out.print(result);
    }

}