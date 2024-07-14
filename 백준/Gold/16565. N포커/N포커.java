import java.io.*;
import java.util.*;

public class Main {

    static private int N;
    static private int MOD = 10007;
    static private long[] arr;
    static private long[][] c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        c = new long[53][53];
        arr = new long[53];
        c[1][0] = 1;
        c[1][1] = 1;

        for (int i = 2; i <= 52; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    c[i][j] = 1;
                    continue;
                }
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
            }
        }

        for (int i = 1; i <= 52; i++) {
            arr[i] = c[52][i];
        }

        dfs(0, 0, 1);

        for (int i = 1; i <= 52; i++) {
            if (arr[i] < 0) {
                arr[i] += MOD;
            }
        }

        N = Integer.parseInt(br.readLine());

        System.out.print(arr[N]);
    }

    static private void dfs (int lv, int card, long num) {
        if (lv == 13) {
            arr[card] -= num;
            if (arr[card] < 0) {
                arr[card] += MOD;
            }
            return;
        }
        for (int i = 0; i <= 3; i++) {
            dfs(lv + 1, card + i, (num * c[4][i]) % MOD);
        }
    }
}