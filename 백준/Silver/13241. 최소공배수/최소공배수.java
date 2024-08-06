import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        long gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;

        System.out.print(gcd*a*b);
    }

    public static long GCD(long a, long b) {
        while(true) {
            if (a%b == 0) {
                return b;
            }
            long tmp = a%b;
            a = b;
            b = tmp;
        }
    }
}