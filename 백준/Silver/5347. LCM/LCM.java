import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long l = lcm(a, b);
            a /= l;
            b /= l;
            l *= a * b;
            bw.write(l + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
    static private long lcm(long a, long b) {
        while(a%b != 0) {
            long tmp = b;
            b = a%b;
            a = tmp;
        }
        return b;
    }
}