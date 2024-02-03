import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();

        int result = Math.abs(A - B);

        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();
            result = Math.min(result, Math.abs(B - tmp) + 1);
        }

        System.out.print(result);
    }
}