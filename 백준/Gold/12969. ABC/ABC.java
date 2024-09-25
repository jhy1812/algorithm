import java.io.*;
import java.util.*;

public class Main {

    public static boolean check = false;
    public static int N, K;
    public static String result;
    public static boolean[][][][] dp;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        result = "";
        dp = new boolean[N+1][N+1][N+1][N*(N-1)/2+1];

        dfs(0, 0, 0, 0, "");

        if (check) {
            System.out.print(result);
        }
        else {
            System.out.print(-1);
        }
    }

    public static void dfs(int lv, int a, int b, int p, String s) {
        if (check || dp[lv][a][b][p]) return;
        if (lv == N) {
            if (p == K) {
                result = s;
                check = true;
            }
            return;
        }
        dp[lv][a][b][p] = true;
        dfs(lv+1, a+1, b, p, s.substring(0, lv)+"A");
        dfs(lv+1, a, b+1, p+a, s.substring(0, lv)+"B");
        dfs(lv+1, a, b, p+a+b, s.substring(0, lv)+"C");
    }
}