import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] arr = new int[10];

        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();
            arr[tmp]++;
        }

        for (int i = 0; i < 10; i++) {
            if (arr[i] == 1) {
                System.out.println("YES");
                if (i == 0) {
                    System.out.print(0);
                }
                else if (i == 1) {
                    System.out.print("111");
                }
                else {
                    System.out.print(i + String.valueOf(i));
                }
                break;
            }
        }
    }
}