import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int result = 0;
        int market = 0;

        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();

            if (market == tmp) {
                market++;
                market %= 3;
                result++;
            }
        }

        System.out.print(result);
    }
}