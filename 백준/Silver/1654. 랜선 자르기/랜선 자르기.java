import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int[] lst = new int[K];
        int result = 0;

        for (int i = 0; i < K; i++) {
            lst[i] = Integer.parseInt(br.readLine());
        }
        long s = 1;
        long e = Integer.MAX_VALUE;

        while (s <= e) {
            long mid = (s + e)/2;
            int cnt = 0;
            boolean check = false;
            for (int i = 0; i < K; i++) {
                cnt += lst[i]/mid;
                if (cnt >= N) {
                    check = true;
                    break;
                }
            }

            if (check) {
                result = (int) mid;
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }

        System.out.print(result);
    }
}