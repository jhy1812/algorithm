import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            String B = st.nextToken();

            int max = 0;
            int min = 0;

            for (int i = N-1; i >= 0; i--) {
                if (B.charAt(i) == '?') {
                    max = max >= N-i ? 2*N-i : 2*N-i-1;
                }
                else if (B.charAt(i) == '1') {
                    max = max >= N-i ? 2*N-i : 2*N-i-1;
                    min = min >= N-i ? 2*N-i : 2*N-i-1;
                }
            }

            max = max == 0 ? 1 : max;
            min = min == 0 ? 1 : min;

            bw.write(max + " " + min + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}