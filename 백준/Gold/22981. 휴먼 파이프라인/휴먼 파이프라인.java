import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());
        long result = K;

        PriorityQueue<Integer> q = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) q.add(Integer.parseInt(st.nextToken()));

        int a = q.poll();
        int b = q.poll();
        int cnt = 1;
        long sum = (long) a + (long) b*(N-1);


        while (!q.isEmpty()) {
            cnt++;
            b = q.poll();
            sum = Math.max(sum, (long) a*cnt + (long) b*(N-cnt));
        }

        result = K/sum;

        if (K%sum != 0) result++;

        System.out.print(result);
    }
}