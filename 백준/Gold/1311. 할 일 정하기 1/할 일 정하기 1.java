import java.io.*;
import java.util.*;

public class Main {

    private static int N;
    private static int size;
    private static int INF = 1000000000;
    private static int[][] cost, dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        size = 1;


        for (int i = 0; i < N; i++) {
            size *= 2;
        }

        cost = new int[N][N];
        dp = new int[N][size];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                cost[i][j] = tmp;
            }
        }

        System.out.print(solve(0, 0, 0));
    }

    private static int solve(int p, int w, int c) {
        if (c == size - 1) {
            return 0;
        }

        if (dp[p][c] != 0) {
            return dp[p][c];
        }
        dp[p][c] = INF;

        for (int i = 0; i < N; i++) {
            if ((c & (1 << i)) == 0) {
                dp[p][c] = Math.min(dp[p][c], solve(p+1, i,c | (1 << i)) + cost[p][i]);
            }
        }

        return dp[p][c];
    }
}