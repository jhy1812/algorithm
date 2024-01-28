import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int tc = 1; tc <= T; tc++) {
            int M = sc.nextInt();
            PriorityQueue<Integer> minq = new PriorityQueue<>();
            PriorityQueue<Integer> maxq = new PriorityQueue<>(Collections.reverseOrder());
            System.out.println(M / 2 + 1);
            int cnt = 0;
            for (int i = 1; i <= M; i++) {
                int tmp = sc.nextInt();
                if (minq.size() == maxq.size()) {
                    if (minq.size() == 0) {
                        maxq.add(tmp);
                    }
                    else {
                        int mintmp = minq.peek();
                        if (mintmp < tmp) {
                            minq.poll();
                            minq.add(tmp);
                            maxq.add(mintmp);
                        }
                        else {
                            maxq.add(tmp);
                        }
                    }
                }
                else if (minq.size() > maxq.size()) {
                    int mintmp = minq.peek();
                    if (mintmp < tmp) {
                        minq.poll();
                        minq.add(tmp);
                        maxq.add(mintmp);
                    }
                    else {
                        maxq.add(tmp);
                    }
                }
                else {
                    int maxtmp = maxq.peek();
                    if (maxtmp > tmp) {
                        maxq.poll();
                        maxq.add(tmp);
                        minq.add(maxtmp);
                    }
                    else {
                        minq.add(tmp);
                    }
                }
                if (i % 2 == 1) {
                    cnt++;
                    System.out.print(maxq.peek() + " ");
                    if (cnt % 10 == 0 || cnt == M / 2 + 1) {
                        System.out.println("");
                    }
                }
            }
        }
    }
}