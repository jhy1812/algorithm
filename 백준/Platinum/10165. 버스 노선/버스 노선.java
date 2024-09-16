import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int last = N;

        PriorityQueue<Line> q = new PriorityQueue<>();
        PriorityQueue<Integer> result = new PriorityQueue<>();

        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (a < b) {
                q.add(new Line(a, b, i));
            }
            else {
                q.add(new Line(a-N, b, i));
                last = Math.min(last, a);
            }
        }

        int end = -N;
        int size = 0;

        for (int i = 1; i <= M; i++) {
            Line l = q.poll();
            int s = l.getS();
            int e = l.getE();
            int n = l.getNum();
            
            if (e > end && s < last) {
                end = e;
                size++;
                result.add(n);
            }
        }

        for (int i = 0; i < size; i++) {
            bw.write(result.poll() + " ");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}
class Line implements Comparable<Line> {
    private int s;
    private int e;
    private int num;

    public Line(int s, int e, int num) {
        this.s = s;
        this.e = e;
        this.num = num;
    }

    public int getS() {
        return this.s;
    }

    public int getE() {
        return this.e;
    }

    public int getNum() {
        return this.num;
    }

    @Override
    public int compareTo(Line l) {
        if (this.s > l.s) {
            return 1;
        }
        else if (this.s == l.s) {
            if (this.e < l.e) {
                return 1;
            }
        }

        return -1;
    }
}
