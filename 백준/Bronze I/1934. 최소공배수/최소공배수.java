import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for  (int tc = 1; tc <= T; tc++) {
            int A = sc.nextInt();
            int B = sc.nextInt();

            if (A > B) {
                int tmp = A;
                A = B;
                B = tmp;
            }

            int gcd = hoje(A, B);

            A /= gcd;
            B /= gcd;

            System.out.println(A * B * gcd);
        }
    }

    private static int hoje(int a, int b) {
        while (true) {
            if (a % b == 0) {
                return b;
            }
            int tmp = a % b;
            a = b;
            b = tmp;
        }
    }
}