import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());

        int ds = Integer.parseInt(br.readLine());
        int result = 0;

        for (int i = 1; i < N; i++) {
            q.add(Integer.parseInt(br.readLine()));
        }

        while (!q.isEmpty()) {
            int tmp = q.poll();
            if (ds > tmp) break;
            result++;
            ds++;
            q.add(--tmp);
        }

        System.out.print(result);
    }
}