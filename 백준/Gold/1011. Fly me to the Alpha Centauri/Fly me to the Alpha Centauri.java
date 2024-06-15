import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int result = 0;
            StringTokenizer st = new StringTokenizer(bf.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());

            long dis = y - x;

            long n = (long) Math.sqrt((double) dis);

            dis -= n * n;
            result += 2 * n - 1;

            while(dis >= n) {
                result++;
                dis -= n;
            }

            if (dis > 0) {
                result++;
            }

            System.out.println(result);
        }
    }
}