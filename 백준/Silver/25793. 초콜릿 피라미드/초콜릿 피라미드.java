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
            long R = Long.parseLong(st.nextToken());
            long C = Long.parseLong(st.nextToken());

            long gap = Math.abs(R-C);
            long N = Math.min(R, C);

            long result = 2*N*(N+1)*(2*N+1)/6 + 2*gap*N*(N+1)/2 - R*(R+1)/2 - C*(C+1)/2 + N + gap*(gap+1)/2;

            bw.write(result + " " + (result-N) + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}