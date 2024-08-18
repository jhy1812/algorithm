import java.io.*;
import java.util.*;

public class Main {
    public static long MOD = 1000000007L;
    public static int N;
    public static long result;
    public static long[] dp;
    public static List<List<Path>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        dp = new long[N+1];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            long w = Long.parseLong(st.nextToken());

            arr.get(u).add(new Path(v, w));
            arr.get(v).add(new Path(u, w));
        }

        dfs(1, 0);

        System.out.print(result);
    }

    public static long dfs(int cur, int par) {
        long sum = 0L;

        for (Path p : arr.get(cur)) {
            int child = p.getV();
            long w = p.getW();
            if (child == par) continue;
            long tmp = (dfs(child, cur) * w + w)%MOD;
            result += sum * tmp;
            result %= MOD;
            sum += tmp;
            sum %= MOD;
            dp[cur] += tmp;
            dp[cur] %= MOD;
        }

        result += dp[cur];
        result %= MOD;

        return dp[cur];
    }
}

class Path {
    private int v;
    private long w;

    public Path(int v, long w) {
        this.v = v;
        this.w = w;
    }

    public int getV() {
        return this.v;
    }

    public long getW() {
        return this.w;
    }
}