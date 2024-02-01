import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int check = 0;
        int cnt = 0;
        String[] arr = new String[N];
        String[] sarr = new String[N];

        for (int i = 0; i < N; i++) {
            String tmp = sc.next();
            arr[i] = tmp;
            sarr[i] = tmp;
        }

        Arrays.sort(sarr);

        for (int i = 0; i < N; i++) {
            if (!arr[i].equals(sarr[i])) {
                cnt++;
                break;
            }
        }

        if (cnt == 0) {
            check = 1;
        }

        cnt = 0;

        for (int i = 0; i < N; i++) {
            if (!arr[i].equals(sarr[N - i - 1])) {
                cnt++;
                break;
            }
        }

        if (cnt == 0) {
            check = 2;
        }

        if (check == 0) {
            System.out.print("NEITHER");
        }
        else if (check == 1) {
            System.out.print("INCREASING");
        }
        else {
            System.out.print("DECREASING");
        }
    }
}