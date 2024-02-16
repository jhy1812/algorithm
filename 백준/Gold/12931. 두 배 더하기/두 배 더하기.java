import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] arr = new int[N];

        int cal1 = 0;
        int cal2 = 0;

        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();
            arr[i] = tmp;
        }

        for (int i = 0; i < N; i++) {
            int tmp = 0;
            while (arr[i] > 0) {
                if (arr[i] % 2 == 0) {
                    arr[i] /= 2;
                    tmp++;
                }
                else {
                    arr[i]--;
                    cal1++;
                }
            }
            cal2 = Math.max(cal2, tmp);
        }

        System.out.print(cal1 + cal2);
    }
}