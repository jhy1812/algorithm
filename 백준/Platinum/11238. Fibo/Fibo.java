import java.io.*;
import java.util.*;

public class Main {
    public static long MOD = 1000000007L;
    public static int gcd;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            gcd = EA(N, M);

            long[][] ret = {{1, 0}, {0, 1}};
            long[][] mat = {{1L, 1L}, {1L, 0L}};

            while (gcd > 0) {
                if (gcd%2 == 1) {
                    ret = mul(ret, mat);
                }
                gcd /= 2;
                mat = mul(mat, mat);
            }

            bw.write(ret[1][0] + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static int EA(int a, int b) {
        while(true) {
            if (a%b == 0) {
                return b;
            }
            int tmp = a%b;
            a = b;
            b = tmp;
        }
    }

    public static long[][] mul(long[][] a1, long[][] a2) {
        long[][] a3 = new long[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                long tmp = 0L;
                for (int k = 0; k < 2; k++) {
                    tmp += a1[i][k] * a2[k][j];
                    tmp %= MOD;
                }
                a3[i][j] = tmp;
            }
        }

        return a3;
    }
}