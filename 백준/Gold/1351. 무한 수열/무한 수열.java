import java.io.*;
import java.util.*;

public class Main {

    public static long N, P, Q;
    public static HashMap<Long, Long> dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Long.parseLong(st.nextToken());
        P = Long.parseLong(st.nextToken());
        Q = Long.parseLong(st.nextToken());

        dp = new HashMap<>();

        System.out.print(dfs(N));
    }

    public static long dfs(long n) {
        if (n == 0) {
            return 1L;
        }

        if (dp.containsKey(n)) {
            return dp.get(n);
        }

        long ret = dfs(n/P) + dfs(n/Q);
        dp.put(n, ret);

        return ret;
    }
}