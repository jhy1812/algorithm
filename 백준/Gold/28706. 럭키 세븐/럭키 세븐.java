import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int N = Integer.parseInt(br.readLine());
            boolean[][] dp = new boolean[N+1][7];
            dp[0][1] = true;

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());

                for (int j = 0; j < 2; j++) {
                    char sign = st.nextToken().charAt(0);
                    int num = Integer.parseInt(st.nextToken());

                    if (sign == '+') {
                        for (int k = 0; k < 7; k++) {
                            if (dp[i][k]) {
                                dp[i+1][(k+num)%7] = true;
                            }
                        }
                    }
                    else {
                        for (int k = 0; k < 7; k++) {
                            if (dp[i][k]) {
                                dp[i+1][(k*num)%7] = true;
                            }
                        }
                    }
                }
            }

            if (dp[N][0]) bw.write("LUCKY\n");
            else bw.write("UNLUCKY\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}