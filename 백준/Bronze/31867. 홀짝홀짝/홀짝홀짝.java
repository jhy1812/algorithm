import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        String K = scanner.next();

        int evenCount = 0;
        int oddCount = 0;

        for (int i = 0; i < N; i++) {
            char digit = K.charAt(i);
            int number = digit - '0';

            if (number % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        if (evenCount > oddCount) {
            System.out.println(0);
        } else if (oddCount > evenCount) {
            System.out.println(1);
        } else {
            System.out.println(-1);
        }

        scanner.close();
    }
}