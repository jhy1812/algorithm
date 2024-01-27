import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int M = sc.nextInt();
        String s = sc.next();
        int result = 3001;

        for (int i = 1; i <= M; i++) {
            int tmp_ret = 0;
            for (int k = 0; k < i; k++) {
                int tmp = 0;
                int cnt = 0;
                int[] arr = new int[4];
                for (int j = k; j < s.length(); j += i) {
                    cnt++;
                    if (s.charAt(j) == 'A') {
                        arr[0]++;
                        tmp = Math.max(tmp, arr[0]);
                    }
                    else if (s.charAt(j) == 'C') {
                        arr[1]++;
                        tmp = Math.max(tmp, arr[1]);
                    }
                    else if (s.charAt(j) == 'G') {
                        arr[2]++;
                        tmp = Math.max(tmp, arr[2]);
                    }
                    else {
                        arr[3]++;
                        tmp = Math.max(tmp, arr[3]);
                    }
                }
                tmp_ret += cnt - tmp;
            }
            result = Math.min(result, tmp_ret);
        }
        System.out.print(result);
    }
}