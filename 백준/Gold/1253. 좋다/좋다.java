import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int result = 0;
        long[] arr = new long[N];
        HashMap<Long, Long> check = new HashMap<Long, Long>();

        for (int i = 0; i < N; i++) {
            long tmp = sc.nextLong();
            arr[i] = tmp;

            if (check.containsKey(tmp)) {
                check.replace(tmp, check.get(tmp) + 1);
            }
            else {
                check.put(tmp, 1L);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                long cor = 0;
                if (arr[i] == 0 || arr[j] == 0) {
                    cor++;
                }
                if (arr[i] == 0 && arr[j] == 0) {
                    cor++;
                }
                if (check.containsKey(arr[i] + arr[j])) {
                    long tmp = check.get(arr[i] + arr[j]);
                    if (cor == 2 && tmp >2) {
                        result += tmp;
                        check.replace(arr[i] + arr[j], 0L);
                    }
                    else if (cor == 1 && tmp > 1) {
                        result += tmp;
                        check.replace(arr[i] + arr[j], 0L);
                    }
                    if (cor == 0) {
                        result += tmp;
                        check.replace(arr[i] + arr[j], 0L);
                    }
                }
            }
        }

        System.out.print(result);
    }
}