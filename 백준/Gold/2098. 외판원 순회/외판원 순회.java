import java.io.*;
import java.util.*;

public class Main {

    private static int N, size;
    private static int[][] arr;
    private static int[][] dp;
    private static final int INF = 1000000000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        size = 1;
        for (int i = 1; i <= N; i++) {
            size *= 2;
        }

        arr = new int[N][N];
        dp = new int[N][1 << N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                arr[i][j] = tmp;
            }
        }

        System.out.print(TSP(0, 1));

    }

    private static int TSP(int st, int visited) {
        if (visited  == size - 1) {
            if (arr[st][0] != 0) return arr[st][0];
            return INF;
        }

        if (dp[st][visited] != 0) return dp[st][visited];

        dp[st][visited] = INF;

        for (int i = 0; i < N; i++) {
            if ((visited & (1 << i)) == 0 && arr[st][i] != 0) {
                dp[st][visited] = Math.min(dp[st][visited], TSP(i, visited | (1 << i)) + arr[st][i]);
            }
        }

        return dp[st][visited];
    }
}