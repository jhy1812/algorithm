import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int N = Integer.parseInt(br.readLine());

            int[] pa = new int[N+1];
            int[] in = new int[N+1];

            for (int i = 1; i <= N; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                pa[a] = i;
                in[i] = b;
            }

            int result = 0;
            int rank = Integer.MAX_VALUE;

            for (int i = 1; i <= N; i++) {
                if (in[pa[i]] < rank) {
                    result++;
                    rank = in[pa[i]];
                }
            }

            bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}