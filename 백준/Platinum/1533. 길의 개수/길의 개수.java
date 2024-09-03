import java.io.*;
import java.util.*;

public class Main {

    public static long MOD = 1000003L;
    public static int N, S, E, T;
    public static long[][] am, ret;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        am = new long[5*N][5*N];
        ret = new long[5*N][5*N];

        for (int i = 0; i < 5*N; i++) {
            ret[i][i] = 1L;
        }

        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < N; j++) {
                int a = tmp.charAt(j) - '0';
                if (a == 0) continue;

                am[5*i][5*j+a-1]++;

                for (int k = 5*j+1; k <= 5*j+a-1; k++) {
                    am[k][k-1] = 1;
                }
            }
        }

        while (T > 0) {
            if (T%2 == 1) {
                ret = mul(ret, am);
            }
            am = mul(am, am);
            T /= 2;
        }

        System.out.print(ret[5*(S-1)][5*(E-1)]);
    }

    public static long[][] mul(long[][] a1, long[][]a2) {
        long[][] a3 = new long[5*N][5*N];
        for (int i = 0; i < 5*N; i++) {
            for (int j = 0; j < 5*N; j++) {
                long tmp = 0L;
                for (int k = 0; k < 5*N; k++) {
                    tmp += a1[i][k] * a2[k][j];
                    tmp %= MOD;
                }
                a3[i][j] = tmp;
            }
        }

        return a3;
    }
}