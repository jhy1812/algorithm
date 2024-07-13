import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N + 1];
        long[] lst = new long[N + 1];

        HashMap<Integer, Integer> check  = new HashMap<Integer, Integer>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            arr[i] = tmp;
            if (!check.containsKey(tmp)) {
                check.put(tmp, i);
            }
            else {
                check.replace(tmp, i);
            }
            lst[i] = tmp + lst[i - 1];
        }

        long sum = 0;
        int cnt = 0;

        for (int i = 1; i <= N; i++) {
            long tmp = lst[check.get(arr[i])] - lst[i - 1];

            if (tmp > sum) {
                cnt = 1;
                sum = tmp;
            }
            else if (tmp == sum) {
                cnt++;
            }
        }

        System.out.print(sum + " " + cnt);
    }
}