import java.io.*;
import java.util.*;

public class Main {

    public static boolean check = false;
    public static int N, K;
    public static char[] ret;
    public static StringBuilder result;
    public static boolean[][][][] dp;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        result = new StringBuilder();
        ret = new char[N];
        dp = new boolean[N+1][N+1][N+1][N*(N-1)/2+1];

        dfs(0, 0, 0, 0);

        if (check) {
            System.out.print(result.toString());
        }
        else {
            System.out.print(-1);
        }
    }

    public static void dfs(int lv, int a, int b, int p) {
        if (check || dp[lv][a][b][p]) return;
        if (lv == N) {
            if (p == K) {
                for (int i = 0; i < N; i++) {
                    result.append(ret[i]);
                }
                check = true;
            }
            return;
        }
        dp[lv][a][b][p] = true;
        ret[lv] = 'A';
        dfs(lv+1, a+1, b, p);
        ret[lv] = 'B';
        dfs(lv+1, a, b+1, p+a);
        ret[lv] = 'C';
        dfs(lv+1, a, b, p+a+b);
    }
}