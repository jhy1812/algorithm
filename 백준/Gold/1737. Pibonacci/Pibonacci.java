import java.io.*;
import java.util.*;

public class Main {

    static public long MOD = 1000000000000000000L;
    static public double pi = 3.1415926535;

    static public long[][] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bf.readLine());
        arr = new long[n + 1][400];

        arr[1][0] = 1;

        for (int i = 2; i <= n; i++) {
            if (2 <= i && i < 4) {
                arr[i][0] = 1;
                continue;
            }
            rec(i, 0);
        }

        System.out.print(arr[n][0]);
    }

    static private long rec(int n, int a) {
        if (0 <= n && n < 4) {
            return 1;
        }
        if (0 <= n - a * pi && n - a * pi <= pi) {
            arr[n][a] = 1;
            return arr[n][a];
        }
        if (arr[n - 1][a] == 0) {
            arr[n - 1][a] = rec(n - 1, a);
        }
        if (arr[n][a + 1] == 0) {
            arr[n][a + 1] = rec(n, a + 1);
        }

        arr[n][a] += arr[n - 1][a] % MOD + arr[n][a + 1] % MOD;
        arr[n][a] %= MOD;
        return arr[n][a];
    }
}