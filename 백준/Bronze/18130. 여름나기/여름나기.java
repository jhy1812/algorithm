import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());
        long Q = Long.parseLong(st.nextToken());
        int num = 0;
        long cost = Long.MAX_VALUE;

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(bf.readLine());
            long P = Long.parseLong(st.nextToken());
            long K = Long.parseLong(st.nextToken());
            long C = Long.parseLong(st.nextToken());

            long tmp = P + (Q / K) * (Q / K + 1) * C / 2;

            if (Q % K == 0) {
                tmp -= (Q / K) * C;
            }

            if (cost > tmp) {
                num = i;
                cost = tmp;
            }
        }

        System.out.print(num + " " + cost);
    }
}