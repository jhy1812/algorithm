import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        long[] arr = new long[63];
        arr[0] = 1;

        for (int i = 1; i < 63; i++) {
            arr[i] = 2*arr[i-1];
        }

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            long N = Long.parseLong(st.nextToken());
            long K = Long.parseLong(st.nextToken());
            K++;
            int n = 0;
            for (int i = 62; i >= 1; i--) {
                if (K >= arr[i]) {
                    n = i;
                    break;
                }
            }
            K--;
            N -= arr[n] - 1;
            K -= arr[n] - 1;

            long q = N / arr[n];
            long r = N % arr[n];

            long ls;
            long rs;
            if (K != 0) {
                if (K <= r) {
                    q++;
                }
                q--;
                ls = q/2 + q%2;
                rs = q/2;
            }
            else {
                ls = q;
                rs = q;
                if (r != 0) {
                    if (arr[n] / 2 <= r) {
                        ls++;
                    }
                }
            }

            System.out.println("Case #" + tc + ": " + ls + " " + rs);
        }
    }
}