import java.io.*;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int len = 0;
        int right = Integer.MIN_VALUE;

        StringTokenizer st;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if (x >= right) {
                len += y - x;
                right = y;
            }
            else {
                if (y > right) {
                    len += y - right;
                    right = y;
                }
            }
        }

        System.out.print(len);
    }
}