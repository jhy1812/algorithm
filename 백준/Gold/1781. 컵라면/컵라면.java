import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int result = 0;
        PriorityQueue<Pair> q = new PriorityQueue<>();
        PriorityQueue<Integer> q2 = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            q.add(new Pair(a, b));
        }

        for (int i = 0; i < N; i++) {
            Pair tmp = q.poll();

            if (tmp.getDead() > q2.size()) {
                q2.add(tmp.getCup());
                result += tmp.getCup();
            }
            else {
                int tmpCup = q2.poll();
                if (tmpCup < tmp.getCup()) {
                    q2.add(tmp.getCup());
                    result += tmp.getCup() - tmpCup;
                }
                else {
                    q2.add(tmpCup);
                }
            }
        }
        System.out.print(result);
    }
}

class Pair implements Comparable<Pair> {
    private int dead;
    private int cup;

    public Pair(int dead, int cup) {
        this.dead = dead;
        this.cup = cup;
    }

    public int getDead() {
        return this.dead;
    }

    public int getCup() {
        return this.cup;
    }

    @Override
    public int compareTo(Pair Pair) {
        if (Pair.dead < dead) {
            return 1;
        }
        else if (Pair.dead > dead) {
            return -1;
        }
        return 0;
    }
}