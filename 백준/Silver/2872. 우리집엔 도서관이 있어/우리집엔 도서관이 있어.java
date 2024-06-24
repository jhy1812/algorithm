import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());
        int result = 0;
        int check = 0;
        int[] arr = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            int tmp = Integer.parseInt(bf.readLine());
            arr[tmp] = i;
            if (tmp == N) {
                check = i;
            }
        }

        for (int i = N - 1; i >= 1; i--) {
            if (arr[i] > check) {
                result++;
                check = 0;
            }
            else {
                check = arr[i];
            }
        }

        System.out.print(result);
    }
}