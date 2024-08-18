import java.io.*;
import java.util.*;

public class Main {

    public static int n;
    public static long result;
    public static long[] dp;
    public static int[] node;
    public static List<List<Long>> lst;
    public static List<List<Path>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while (true) {
            n = Integer.parseInt(br.readLine());
            if (n == 0) {
                break;
            }

            result = Long.MAX_VALUE;
            dp = new long[n];
            node = new int[n];
            arr = new ArrayList<>();
            lst = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                arr.add(new ArrayList<>());
                lst.add(new ArrayList<>());
            }

            for (int i = 1; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                arr.get(u).add(new Path(v, w));
                arr.get(v).add(new Path(u, w));
            }

            dfs(0, -1);
            dfs2(0, -1, 0);

            bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.flush();
    }

    public static void dfs(int cur, int par) {
        node[cur]++;
        for (Path p : arr.get(cur)) {
            int child = p.getV();
            if (child == par) {
                lst.get(cur).add(0L);
                continue;
            }
            dfs(child, cur);
            dp[cur] += dp[child] + (long) p.getW() * node[child];
            node[cur] += node[child];
            lst.get(cur).add(dp[child] + (long) p.getW() * node[child]);
        }
    }

    public static void dfs2(int cur, int par, long cost) {
        dp[cur] += cost;
        result = Math.min(result, dp[cur]);
        for (int i = 0; i < arr.get(cur).size(); i++) {
            Path p = arr.get(cur).get(i);
            int child = p.getV();
            if (child == par) continue;
            dfs2(child, cur, dp[cur] - lst.get(cur).get(i) + (long) p.getW() * (n - node[child]));
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