import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        long result = 0L;
        PriorityQueue<Long> q = new PriorityQueue<>();

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            long tmp = Long.parseLong(st.nextToken());
            result += tmp;
            q.add(tmp);
        }

        for (int i = 0; i < m; i++) {
            long a = q.poll();
            long b = q.poll();
            result += a + b;
            q.add(a + b);
            q.add(a + b);
        }

        System.out.print(result);
    }
}