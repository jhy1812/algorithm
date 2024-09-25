import java.io.*;
import java.util.*;

public class Main {

    public static int ll = -1000000000;
    public static int rl = 1000000000;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long result = 0;
        int[] lst = new int[100001];

        PriorityQueue<Integer> q = new PriorityQueue<>();

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            q.add(Integer.parseInt(st.nextToken()));
        }

        q.add(rl);

        int s = ll;
        int e = q.poll();

        for (int i = 0; i < N; i++) {
            lst[Math.min(100000, (e-s-1)/2 + (e-s-1)%2)]++;
            lst[Math.min(100000, (q.peek()-e-1)/2)]++;
            s = e;

            if (i == N-1) {
                e = rl;
                continue;
            }
            e = q.poll();
        }

        int num = 2*N - lst[0];
        int cnt = 0;

        for (int i = 1; i <= 100000; i++) {
            if (cnt + num > K) {
                result += (long) (K-cnt) * i;
                break;
            }
            cnt += num;
            result += (long) num * i;
            num -= lst[i];
        }

        System.out.print(result);
    }
}