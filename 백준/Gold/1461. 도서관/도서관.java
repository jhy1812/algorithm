import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int last = 0;
        int result = 0;

        PriorityQueue<Integer> left = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> right = new PriorityQueue<>(Collections.reverseOrder());

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            if (tmp < 0) left.add(-tmp);
            else right.add(tmp);
        }

        while (!left.isEmpty()) {
            int cnt = M;
            int dis = 0;
            while (!left.isEmpty() && cnt-- > 0) {
                dis = Math.max(dis, left.poll());
            }
            last = Math.max(last, dis);
            result += dis;
        }

        while (!right.isEmpty()) {
            int cnt = M;
            int dis = 0;
            while (!right.isEmpty() && cnt-- > 0) {
                dis = Math.max(dis, right.poll());
            }
            last = Math.max(last, dis);
            result += dis;
        }

        result *= 2;
        result -= last;

        System.out.print(result);
    }
}