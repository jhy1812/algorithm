import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());

        for (int tc = 1; tc <= T; tc++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());

            int result = 0;
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (b >= c) {
                result += (b - c + 1);
                b -= (b - c + 1);
            }
            if (a >= b) {
                result += (a - b + 1);
                a -= (a - b + 1);
            }

            System.out.print("#" + tc + " ");
            if (a <= 0) {
                System.out.println(-1);
            }
            else {
                System.out.println(result);
            }
        }
    }
}