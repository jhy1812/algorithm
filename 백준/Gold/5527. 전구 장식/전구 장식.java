import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        int len = 1;
        int cnt = 0;
        int sum = 0;
        int[] arr = new int[3];

        st = new StringTokenizer(br.readLine());

        int be = Integer.parseInt(st.nextToken());

        for (int i = 1; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());

            if (be != tmp) {
                len++;
            }
            else {
                sum -= arr[cnt%3];
                arr[(cnt++)%3] = len;
                sum += len;
                result = Math.max(result, sum);
                len = 1;
            }

            be = tmp;
        }

        sum -= arr[cnt%3];
        sum += len;
        result = Math.max(result, sum);

        System.out.print(result);
    }
}