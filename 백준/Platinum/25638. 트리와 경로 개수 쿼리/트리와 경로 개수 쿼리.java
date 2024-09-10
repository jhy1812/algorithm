import java.io.*;
import java.util.*;

public class Main {

    public static int N, blue, red;
    public static int[] color;
    public static int[][] lst;
    public static long[] dp;
    public static List<List<Integer>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        color = new int[N+1];
        lst = new int[N+1][2];
        dp = new long[N+1];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= N; i++) {
            color[i] = Integer.parseInt(st.nextToken());
            if (color[i] == 0) {
                blue++;
            }
            else {
                red++;
            }
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr.get(u).add(v);
            arr.get(v).add(u);
        }

        dfs(1, 0);

        int Q = Integer.parseInt(br.readLine());

        for (int i = 0; i < Q; i++) {
            int u = Integer.parseInt(br.readLine());
            bw.write(dp[u] + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs(int cur, int par) {
        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs(child, cur);
            dp[cur] += (long) lst[cur][0] * lst[child][1];
            dp[cur] += (long) lst[cur][1] * lst[child][0];
            lst[cur][0] += lst[child][0];
            lst[cur][1] += lst[child][1];
        }

        if (color[cur] == 0) {
            dp[cur] += (long) (blue - lst[cur][0] - 1) * lst[cur][1];
            dp[cur] += (long) (red - lst[cur][1]) * lst[cur][0];
        }
        else {
            dp[cur] += (long) (blue - lst[cur][0]) * lst[cur][1];
            dp[cur] += (long) (red - lst[cur][1] - 1) * lst[cur][0];
        }


        lst[cur][color[cur]]++;
    }
}