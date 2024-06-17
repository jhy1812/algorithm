import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());
        int[] menu = new int[N + 1];
        int cost = 0;

        for (int i = 1; i <= N; i++) {
            int tmp = Integer.parseInt(bf.readLine());
            menu[i] = tmp;
        }

        int M = Integer.parseInt(bf.readLine());

        for (int i = 0; i < M; i++) {
            int tmp = Integer.parseInt(bf.readLine());
            cost += menu[tmp];
        }

        System.out.print(cost);
    }
}