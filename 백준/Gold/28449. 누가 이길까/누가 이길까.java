import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] a = new int[100001];
        int[] b = new int[100001];

        for (int i = 1; i <= N; i++) {
            int tmp = sc.nextInt();
            a[tmp]++;
        }

        for (int i = 1; i <= M; i++) {
            int tmp = sc.nextInt();
            b[tmp]++;
        }

        for (int i = 1; i <= 100000; i++) {
            b[i] += b[i - 1];
        }

        long win = 0;
        long draw = 0;
        long lose = 0;

        for (int i = 1; i <= 100000; i++) {
            if (a[i] != 0) {
                if (i < 100000) {
                    lose += (long) (M - b[i]) * a[i];
                }
                win += (long) b[i - 1] * a[i];
                draw += (long) (b[i] - b[i - 1]) * a[i];
            }
        }

        System.out.print(win + " " + lose + " " + draw);
    }
}