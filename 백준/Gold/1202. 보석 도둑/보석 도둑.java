import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long result = 0L;

        PriorityQueue<Integer> bags = new PriorityQueue<>();
        PriorityQueue<Jewel> q1 = new PriorityQueue<>(new Comparator<Jewel>() {
            @Override
            public int compare(Jewel o1, Jewel o2) {
                return o1.getM() > o2.getM() ? 1 : -1;
            }
        });
        PriorityQueue<Integer> q2 = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            q1.add(new Jewel(M, V));
        }

        for (int i = 0; i < K; i++) {
            bags.add(Integer.parseInt(br.readLine()));
        }

        while (!bags.isEmpty()) {
            int bag = bags.poll();

            while (!q1.isEmpty()) {
                Jewel j = q1.peek();

                if (j.getM() <= bag) {
                    q2.add(j.getV());
                    q1.poll();
                }
                else {
                    break;
                }
            }

            if (!q2.isEmpty()) {
                result += (long) q2.poll();
            }
        }

        System.out.print(result);
    }
}

class Jewel{
    private int m;
    private int v;

    public Jewel(int m, int v) {
        this.m = m;
        this.v = v;
    }

    public int getM() {
        return this.m;
    }

    public int getV() {
        return this.v;
    }
}

