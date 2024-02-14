import java.io.*;
import java.util.*;

public class Main {

    public static long[] result;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            if (a == 0 && b == 0) {
                break;
            }

            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            a--;

            result = new long[10];

            counting(a, -1);
            counting(b, 1);

            for (int i = 0; i < 10; i++) {
                System.out.print(result[i] + " ");
            }
            System.out.println("");
        }

    }

    private static void counting(int N, int state) {
        long mod = 1;

        while (true) {
            if (N / mod == 0) {
                break;
            }

            for (int i = 1; i < 10; i++) {
                result[i] += ((N / (mod * 10)) * mod) * state;
            }

            for (int i = 1; i <= (N / mod) % 10; i++) {
                if (i == (N / mod) % 10) {
                    result[i] += (N % mod + 1) * state;
                } else {
                    result[i] += mod * state;
                }
            }

            if ((N / mod) % 10 == 0) {
                if (N / (mod * 10) > 0) {
                    result[0] += (N / (mod * 10) - 1) * mod * state;
                }
                result[0] += (N % mod + 1) * state;
            } else {
                result[0] += ((N / (mod * 10)) * mod) * state;
            }

            mod *= 10;
        }
    }
}