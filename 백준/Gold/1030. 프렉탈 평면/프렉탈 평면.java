import java.io.*;
import java.util.*;

public class Main {

    public static int s, N, K, R1, R2, C1, C2, L;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        s = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        R1 = Integer.parseInt(st.nextToken());
        R2 = Integer.parseInt(st.nextToken());
        C1 = Integer.parseInt(st.nextToken());
        C2 = Integer.parseInt(st.nextToken());

        L = 1;

        for (int i = 0; i < s; i++) L *= N;

        for (int i = R1; i <= R2; i++) {
            for (int j = C1; j <= C2; j++) {
               bw.write(String.valueOf(solve(L, i, j)));
            }
            bw.write("\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static int solve(int n, int r, int c) {
        if (n == 1) {
            return 0;
        }

        int l = n/N;

        if (l*((N-K)/2) <= r && r < l*((N-K)/2+K) && l*((N-K)/2) <= c && c < l*((N-K)/2+K)) return 1;

        return solve(n/N, r%l, c%l);
    }

}