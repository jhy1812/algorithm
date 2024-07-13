import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] arr = new int[1000001];
        int[] lst = new int[500001];

        for (int i = 2; i <= 500000; i++) {
            if (arr[i] == 1) {
                continue;
            }
            for (int j = 2 * i; j <= 1000000; j += i) {
                arr[j] = 1;
            }
        }

        for (int i = 2; i <= 500000; i++) {
            if (arr[2 * i - 1] == 0) {
                lst[i]++;
            }

            lst[i] += lst[i - 1];
        }

        int Q = Integer.parseInt(br.readLine());
        StringTokenizer st;

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());

            System.out.println(lst[R] - lst[L]);
        }
    }
}