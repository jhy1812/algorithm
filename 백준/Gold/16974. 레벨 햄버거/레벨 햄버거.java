import java.io.*;
import java.util.*;

public class Main {
    public static long result;
    public static long[] bg;
    public static long[] pt;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());
        long X = Long.parseLong(st.nextToken());

        bg = new long[N + 1];
        pt = new long[N + 1];

        bg[0] = 1;
        pt[0] = 1;

        for (int i = 1; i <= N; i++) {
            bg[i] = 2 * bg[i - 1] + 3;
            pt[i] = 2 * pt[i - 1] + 1;
        }

        sol(N, X);

        System.out.print(result);
    }

    private static void sol(int n, long x) {
        if (n == 0) {
            if (x > 0L) {
                result++;
            }
            return;
        }
        if (x <= 0) {
            return;
        }

        if (x == bg[n]) {
            result += pt[n];
            return;
        }

        if (x <= bg[n] / 2L) {
            sol(n - 1, x - 1L);
        }
        else if (x > bg[n] / 2L + 1L) {
            result++;
            result += pt[n - 1];
            sol(n - 1, x - bg[n - 1] - 2L);
        }
        else {
            result++;
            result += pt[n - 1];
        }
    }
}