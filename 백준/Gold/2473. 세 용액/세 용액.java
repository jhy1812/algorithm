import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            arr[i] = tmp;
        }

        Arrays.sort(arr);

        long sum = Long.MAX_VALUE;
        int a, b, c;
        a = 0;
        b = 0;
        c = 0;
        for (int i = 1; i < N-1; i++) {
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < N) {
                long sum1 = (long) arr[l] + arr[i] + arr[r];
                if (Math.abs(sum) > Math.abs(sum1)) {
                    sum = sum1;
                    a = arr[l];
                    b = arr[i];
                    c = arr[r];
                }
                if (sum1 > 0) {
                    l--;
                }
                else if (sum1 < 0) {
                    r++;
                }
                else {
                    break;
                }
            }
        }

        System.out.print(a + " " + b + " " + c);
    }
}