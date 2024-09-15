import java.io.*;
import java.util.*;

public class Main {

    static public int N;
    static public int[] dp;
    static public long[] result;
    static public List<List<Integer>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        dp = new int[N+1];
        result = new long[N+1];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr.get(x).add(y);
            arr.get(y).add(x);
        }

        dfs(1, 0);

        for (int i = 1; i <= N; i++) {
            bw.write(result[i] + " \n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs(int cur, int par) {
        for (int child : arr.get(cur)) {
            if (child == par) continue;
            dfs(child, cur);
            result[cur] += (long) 2*dp[cur]*dp[child];
            dp[cur] += dp[child];
        }

        dp[cur]++;
        result[cur] += (long) 2*(N-dp[cur])*(dp[cur]-1) + 2L*(N-1);
    }
}
