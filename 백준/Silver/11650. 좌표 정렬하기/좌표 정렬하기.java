import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Dot> q = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            q.add(new Dot(x, y));
        }

        while (!q.isEmpty()) {
            Dot d = q.poll();
            bw.write(d.getX() + " " + d.getY() + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}

class Dot implements Comparable<Dot> {
    private int x;
    private int y;

    public Dot(int x, int y) {
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
    public int compareTo(Dot d) {
        if (this.x > d.getX()) return 1;
        else if (this.x == d.getX()) {
            if (this.y > d.getY()) return 1;
        }

        return -1;
    }
}