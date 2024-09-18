import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        PriorityQueue<Integer> q1 = new PriorityQueue<>();
        PriorityQueue<Integer> q2 = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(br.readLine());

            if (tmp <= 0) {
                q1.add(tmp);
            }
            else if (tmp > 1) {
                q2.add(tmp);
            }
            else {
                result++;
            }
        }

        int cnt = 0;
        int num = 0;
        while(!q1.isEmpty()) {
            if (cnt%2 == 0) {
                num = 0;
                num += q1.poll();
            }
            else {
                num *= q1.poll();
                result += num;
            }
            cnt++;
        }

        if (cnt%2 == 1) {
            result += num;
        }

        cnt = 0;
        while(!q2.isEmpty()) {
            if (cnt%2 == 0) {
                num = 0;
                num += q2.poll();
            }
            else {
                num *= q2.poll();
                result += num;
            }
            cnt++;
        }

        if (cnt%2 == 1) {
            result += num;
        }

        System.out.print(result);
    }
}