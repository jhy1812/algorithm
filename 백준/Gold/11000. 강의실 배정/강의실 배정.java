import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        PriorityQueue<Pair> q1 = new PriorityQueue<>();
        PriorityQueue<Integer> q2 = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            q1.add(new Pair(a, b));
        }

        for (int i = 0; i < N; i++) {
            Pair tmp = q1.poll();
            if (q2.isEmpty()) {
                q2.add(tmp.getEd());
            }
            else {
                int ed = q2.peek();
                if (ed <= tmp.getSt()) {
                    q2.poll();
                    q2.add(tmp.getEd());
                }
                else {
                    q2.add(tmp.getEd());
                }
            }
        }
        System.out.print(q2.size());
    }
}

class Pair implements Comparable<Pair> {

    private int st;
    private int ed;

    public Pair(int st, int ed) {
        this.st = st;
        this.ed = ed;
    }

    public int getSt() {
        return this.st;
    }

    public int getEd() {
        return this.ed;
    }

    @Override
    public int compareTo(Pair Pair) {
        if (Pair.st < st) {
            return 1;
        }
        else if (Pair.st > st) {
            return -1;
        }
        return 0;
    }
}
