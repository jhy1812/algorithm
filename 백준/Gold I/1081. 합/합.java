import java.io.*;
import java.util.*;

public class Main {

    public static long[] result;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int L = sc.nextInt();
        int U = sc.nextInt();

        result = new long[10];

        L--;
        counting(L, -1);
        counting(U, 1);

        long ret = 0;

        for (int i = 1; i < 10; i++) {
            ret += i * result[i];
        }

        System.out.print(ret);
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