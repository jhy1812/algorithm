import java.io.*;
import java.util.*;

public class Main {
    public static HashMap<Integer, Long> dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        dp = new HashMap<>();

        System.out.print(dfs(N));
    }

    public static long dfs(int n) {
        if (dp.containsKey(n)) {
            return dp.get(n);
        }
        if (n == 1) {
            return 0L;
        }
        long ret = dfs(n/2) + dfs(n/2 + n%2) + (long) (n / 2) * (n/2 + n%2);
        dp.put(n, ret);
        return ret;
    }
}