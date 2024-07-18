import java.io.*;
import java.util.*;

public class Main {

    static private final int MOD = 2000003;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[2000000];
        long result = 1;
        PriorityQueue<Pair> q = new PriorityQueue<>();

        for(int i = 2; i < 2000000; i++) {
            if (arr[i] == 1) {
                continue;
            }
            q.add(new Pair(0, i));

            for(int j = 2*i; j < 2000000; j += i) {
                arr[j] = 1;
            }
        }

        for(int i = 0; i < N; i++) {
            Pair pair = q.poll();
            long a = pair.getA();
            long b = pair.getB();

            q.add(new Pair(a*a*MOD + 2*a*b + b*b/MOD, ((b%MOD)*(b%MOD))%MOD));

            result *= b;
            result %= MOD;
        }

        System.out.print(result);
    }
}

class Pair implements Comparable<Pair> {
    private long a;
    private long b;

    public Pair(long a, long b) {
        this.a = a;
        this.b = b;
    }

    public long getA() {
        return this.a;
    }

    public long getB() {
        return this.b;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.a > p.a) {
            return 1;
        }
        else if (this.a == p.a) {
            if (this.b > p.b) {
                return 1;
            }
        }

        return -1;
    }
}