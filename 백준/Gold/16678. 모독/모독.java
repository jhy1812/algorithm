import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        long result = 0L;
        boolean[] arr = new boolean[100001];
        PriorityQueue<Integer> q = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            q.add(Integer.parseInt(br.readLine()));
        }

        int cnt = 1;

        while (!q.isEmpty()) {
            int tmp = q.poll();
            if (cnt > tmp) continue;
            if (cnt < tmp) {
                if (!arr[cnt]) {
                    arr[cnt] = true;
                    result += tmp - cnt;
                    cnt++;
                }
            }
            else {
                if (!arr[cnt]) arr[cnt] = true;
                cnt ++;
            }
        }

        System.out.print(result);
    }
}