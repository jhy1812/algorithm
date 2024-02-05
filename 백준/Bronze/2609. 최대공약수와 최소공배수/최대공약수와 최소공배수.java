import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a, b;

        a = sc.nextInt();
        b = sc.nextInt();

        int gcd = hoje(a, b);

        a /= gcd;
        b /= gcd;

        System.out.println(gcd);
        System.out.print(a * b * gcd);
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