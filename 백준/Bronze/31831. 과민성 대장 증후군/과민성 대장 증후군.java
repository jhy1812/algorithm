import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int str = 0;
        int result = 0;

        st = new StringTokenizer(bf.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            str += tmp;

            if (str < 0) {
                str = 0;
            }

            if (str >= M) {
                result++;
            }
        }

        System.out.print(result);
    }
}