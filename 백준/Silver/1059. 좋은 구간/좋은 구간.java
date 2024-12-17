import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int L = Integer.parseInt(br.readLine());
        int result = 0;
        boolean check = false;
        PriorityQueue<Integer> q = new PriorityQueue<>();

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < L; i++) {
            q.add(Integer.parseInt(st.nextToken()));
        }

        int n = Integer.parseInt(br.readLine());
        int a = q.poll();
        int b = 0;

        if (L == 1 || n < a) {
            if (n == a) result = 0;
            else {
                result = ((a-1)*(a-2))/2;
                result -= ((n-1)*(n-2))/2;
                result -= ((a-n-1)*(a-n-2))/2;
            }
            check = true;
        }

        while (!q.isEmpty() && !check) {
            b = q.poll();
            if (n == a || n == b) break;
            if (b < n) a = b;
            else break;
        }

        if (n != a && n != b && L > 1) {
            result = ((b-a-1)*(b-a-2))/2;
            result -= ((n-a-1)*(n-a-2))/2;
            result -= ((b-n-1)*(b-n-2))/2;
        }

        System.out.print(result);
    }
}