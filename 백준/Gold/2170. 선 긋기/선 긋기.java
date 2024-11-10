import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int result = 0;

        int s = -1000000001;
        int e = -1000000001;

        PriorityQueue<Pair> q = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            q.add(new Pair(x, y));
        }

        while(!q.isEmpty()) {
            Pair p = q.poll();
            int x = p.getX();
            int y = p.getY();

            if (x <= e) {
                if (y > e) {
                    e = y;
                }
            }
            else {
                result += e-s;
                s = x;
                e = y;
            }
        }

        result += e-s;

        System.out.print(result);
    }
}

class Pair implements Comparable<Pair>{
    private int x;
    private int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.x > p.getX()) {
            return 1;
        }
        else if (this.x == p.getX()) {
            if (this.y > p.getY()) {
                return 1;
            }
        }

        return -1;
    }
}