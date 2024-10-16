import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        PriorityQueue<Pair> q = new PriorityQueue<>();

        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= N; i++) {
            q.add(new Pair(Integer.parseInt(st.nextToken()), i));
        }

        int last = q.poll().getS();

        while(!q.isEmpty()) {
            int now = q.poll().getS();

            if (Math.abs(last-now) != 1) result++;

            last = now;
        }

        System.out.print(result);
    }
}

class Pair implements Comparable<Pair> {

    private int n;
    private int s;

    public Pair(int n, int s) {
        this.n = n;
        this.s = s;
    }

    public int getN() {
        return this.n;
    }

    public int getS() {
        return this.s;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.n > p.getN()) return 1;
        return -1;
    }
}