import java.io.*;
import java.util.*;

public class Main {

    public static long MOD = 1000000000L;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            long x = Long.parseLong(br.readLine());
            x--;

            long[][] result = {{2L, 1L}, {1L, 1L}};
            long[][] mat = {{1L, 1L}, {1L, 0L}};

            while (x > 0) {
                if (x%2 == 1) {
                    result = mul(result, mat);
                }
                x /= 2;
                mat = mul(mat, mat);
            }

            bw.write(result[1][1] + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static long[][] mul(long[][] a1, long[][]a2) {
        long[][] a3 = new long[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                long tmp = 0L;
                for (int k = 0; k < 2; k++) {
                    tmp += (a1[i][k] * a2[k][j]) % MOD;
                    tmp %= MOD;
                }
                a3[i][j] = tmp;
            }
        }

        return a3;
    }
}