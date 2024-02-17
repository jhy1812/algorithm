import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String num = sc.next();

        int N = num.length();
        long result = 0;

        for (int i = 0; i < N; i++) {
            long tmp = 1;
            for (int j = 0; j < N - i - 1; j++) {
                tmp *= 16;
            }
            if (num.charAt(i) >= 'A' && num.charAt(i) <= 'F') {
                tmp *= (num.charAt(i) - 'A' + 10);
            }
            else {
                tmp *= (num.charAt(i) - '0');
            }
            result += tmp;
        }

        System.out.print(result);
    }
}