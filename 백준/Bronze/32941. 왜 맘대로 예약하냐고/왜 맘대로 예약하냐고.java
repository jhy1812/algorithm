import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(br.readLine());
        boolean result = true;

        for (int i = 0; i < N; i++) {
            int K = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            boolean check = false;

            for (int j = 0; j < K; j++) {
                int tmp = Integer.parseInt(st.nextToken());

                if (tmp == X) {
                    check = true;
                    break;
                }
            }

            if (!check) result = false;
        }

        if (result) System.out.print("YES");
        else System.out.print("NO");
    }
}