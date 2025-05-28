import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int result = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken());
            int I = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            if (T > S) {
                int tmp = T-S;
                int cnt = 0;

                if (tmp%I == 0) {
                    cnt = tmp/I;
                    if (--C >= cnt) {
                        result = 0;
                    }
                }
                else {
                    cnt = tmp/I + 1;
                    if (--C >= cnt) {
                        result = Math.min(result, I-(tmp%I));
                    }
                }

            }
            else {
                result = Math.min(result, S-T);
            }
        }

        if (result == Integer.MAX_VALUE) System.out.print(-1);
        else System.out.print(result);
    }
}