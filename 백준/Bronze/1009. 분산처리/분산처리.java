import java.io.*;
import java.util.*;

public class Main {

    public static int MOD = 10;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int n = 1;

            while (b > 0) {
                if (b%2 == 1) n *= a;
                n %= 10;
                b /= 2;
                a *= a;
                a %= MOD;
            }

            n = n == 0 ? 10 : n;
            bw.write(n + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}