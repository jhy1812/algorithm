import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int result = 0;

            Queue<Pair> q1 = new LinkedList<>();
            PriorityQueue<Integer> q2 = new PriorityQueue<>(Collections.reverseOrder());

            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                int tmp = Integer.parseInt(st.nextToken());
                q1.add(new Pair(tmp, i));
                q2.add(tmp);
            }

            int cnt = 0;

            while (!q2.isEmpty()) {
                cnt++;
                int tmp = q2.poll();

                while (!q1.isEmpty()) {
                    Pair p = q1.poll();
                    int y = p.getY();
                    int x = p.getX();

                    if (y >= tmp) {
                        if (x == M) result = cnt;
                        break;
                    }
                    else q1.add(p);
                }

                if (result > 0) break;
            }

            bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}

class Pair {

    private int y;
    private int x;

    public Pair(int y, int x) {
        this.y = y;
        this.x = x;
    }

    public int getY() {
        return this.y;
    }

    public int getX() {
        return this.x;
    }
}