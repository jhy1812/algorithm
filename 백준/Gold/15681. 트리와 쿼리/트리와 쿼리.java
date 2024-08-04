import java.io.*;
import java.util.*;

public class Main {

    public static int N, R, Q;
    public static int[] dp;
    public static List<List<Integer>> arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        dp = new int[N + 1];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr.get(u).add(v);
            arr.get(v).add(u);
        }

        dfs(R, 0);

        for (int i = 0; i < Q; i++) {
            int u = Integer.parseInt(br.readLine());
            bw.write(dp[u] + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    private static int dfs(int cur, int parent) {
        dp[cur]++;

        for (int child : arr.get(cur)) {
            if (child == parent) continue;
            dp[cur] += dfs(child, cur);
        }

        return dp[cur];
    }
}