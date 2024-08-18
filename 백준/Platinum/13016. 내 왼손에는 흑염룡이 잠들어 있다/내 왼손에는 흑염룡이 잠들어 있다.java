import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int[][] dp;
    public static int[][][] len;
    public static List<List<Path>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        dp = new int[N+1][2];
        len = new int[N+1][2][2];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            arr.get(u).add(new Path(v, w));
            arr.get(v).add(new Path(u, w));
        }

        dfs(1, 0);
        dfs2(1, 0, 0);

        for (int i = 1; i <= N; i++) {
            bw.write(Math.max(dp[i][0], dp[i][1]) + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs(int cur, int par) {
        for (Path p : arr.get(cur)) {
            int child = p.getV();
            int w = p.getW();
            if (child == par) continue;
            dfs(child, cur);
            dp[cur][0] = Math.max(dp[cur][0], dp[child][0] + w);

            if (len[cur][0][1] <= dp[child][0] + w) {
                len[cur][1][0] = len[cur][0][0];
                len[cur][1][1] = len[cur][0][1];
                len[cur][0][0] = child;
                len[cur][0][1] = dp[child][0] + w;
            }
            else if (len[cur][1][1] <= dp[child][0] + w) {
                len[cur][1][0] = child;
                len[cur][1][1] = dp[child][0] + w;
            }
        }
    }

    public static void dfs2(int cur, int par, int cost) {
        dp[cur][1] = cost;

        for (Path p : arr.get(cur)) {
            int child = p.getV();
            int w = p.getW();
            if (child == par) continue;
            if (child == len[cur][0][0]) {
                dfs2(child, cur, Math.max(len[cur][1][1], dp[cur][1]) + w);
            }
            else {
                dfs2(child, cur, Math.max(len[cur][0][1], dp[cur][1]) + w);
            }
        }

    }
}

class Path {
    private int v;
    private int w;

    public Path(int v, int w) {
        this.v = v;
        this.w = w;
    }

    public int getV() {
        return this.v;
    }

    public int getW() {
        return this.w;
    }
}