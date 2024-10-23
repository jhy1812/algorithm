import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        long max = 0L;
        long sum = 0L;
        long[] vote = new long[N+2];

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int q = Integer.parseInt(st.nextToken());
            long x = Long.parseLong(st.nextToken());
            if (q == 1) {
                int p = Integer.parseInt(st.nextToken());
                vote[p] += x;
                if (p != N+1) {
                    max = Math.max(max, vote[p]);
                    sum += x;
                }
            }
            else {
                long y = Long.parseLong(st.nextToken());
                long check = sum+y;
                if (check%N == 0) check /= N;
                else check = check/N + 1;
                check = Math.max(check, max);
                if (vote[N+1]+x > check) bw.write("YES\n");
                else bw.write("NO\n");
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}