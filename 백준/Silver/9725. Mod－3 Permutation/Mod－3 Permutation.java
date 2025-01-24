import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());

            int[][] lst = new int[3][3];

            for (int i = 0; i < n; i++) {
                int tmp = Integer.parseInt(st.nextToken());

                lst[tmp%3][i%3]++;
            }

            int result = 0;

            result += Math.min(lst[0][1], lst[1][0]);
            lst[0][1] -= result;
            lst[1][0] -= result;
            result += Math.min(lst[0][2], lst[2][0]);
            result += Math.min(lst[1][2], lst[2][1]);
            result += 2*Math.max(lst[0][1], lst[1][0]);

            bw.write("Case #" + tc + ": " + result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}