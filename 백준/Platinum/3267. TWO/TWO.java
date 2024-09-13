import java.io.*;
import java.util.*;

public class Main {

    public static int N, S;
    public static int[][] dp;
    public static List<List<Path>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        int result = 0;

        dp = new int[N+1][2];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            arr.get(A).add(new Path(B, C));
            arr.get(B).add(new Path(A, C));
            result += 2*C;
        }

        dfs(S, 0);

        System.out.print(result - Math.max(dp[S][0], dp[S][1]));
    }

    public static void dfs(int cur, int par) {
        for (Path p : arr.get(cur)) {
            int child = p.getV();
            int dis = p.getD();

            if (child == par) continue;

            dfs(child, cur);

            if (dp[cur][1] < dp[cur][0] + dp[child][0] + dis) {
                dp[cur][1] = dp[cur][0] + dp[child][0] + dis;
            }

            if (dp[cur][0] < dp[child][0] + dis) {
                dp[cur][0] = dp[child][0] + dis;
            }

            if (dp[cur][1] < dp[child][1]) {
                dp[cur][1] = dp[child][1];
            }
        }
    }
}

class Path {
    private int v;
    private int d;

    public Path(int v, int d) {
        this.v = v;
        this.d = d;
    }

    public int getV() {
        return this.v;
    }

    public int getD() {
        return this.d;
    }
}