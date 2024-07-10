import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int[] mod = new int[31];
        mod[0] = 1;

        int[] pl = new int[N + 1];
        int[] mi = new int[N + 1];

        long result = 0;

        for (int i = 1; i <= 30; i++) {
            mod[i] = mod[i - 1] * 2;
        }

        st = new StringTokenizer(bf.readLine());
        PriorityQueue<Integer> hb = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> expo = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            hb.add(tmp);
        }

        st = new StringTokenizer(bf.readLine());

        for (int i = 1; i <= K; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            pl[tmp]++;
            if (tmp + L <= N) {
                mi[tmp + L]++;
            }
        }

        int effect = 0;

        for (int i = 1; i <= N; i++) {
            effect += pl[i] - mi[i];
            expo.add(effect);
        }

        for (int i = 0; i < N; i++) {
            int hamburger = hb.poll();
            int coke = expo.poll();

            if (coke <= 30) {
                result += hamburger / mod[coke];
            }
        }

        System.out.print(result);
    }
}