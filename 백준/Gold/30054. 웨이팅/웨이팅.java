import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[] num = new int[N + 1];
        int[] check = new int[300001];
        int ct = 0;
        int result = 0;

        PriorityQueue<Reserve> q = new PriorityQueue<>();

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int t1 = Integer.parseInt(st.nextToken());
            int t2 = Integer.parseInt(st.nextToken());

            if (t1 >= t2) {
                check[t1] = i;
            }

            q.add(new Reserve(t1, t2, i));
        }

        while(!q.isEmpty()) {
            Reserve rev = q.poll();
            int a = rev.getA();
            int r = rev.getR();
            int n = rev.getN();

            if (ct < a) {
                ct = a;
            }

            if (num[n] == 1) {
                continue;
            }

            if (num[check[ct]] == 0 && check[ct] != 0) {
                if (check[ct] == n) {
                    num[n] = 1;
                }
                else {
                    q.add(rev);
                    num[check[ct]] = 1;
                }
            }
            else {
                num[n] = 1;
            }
            result = Math.max(result, ct - a);
            ct++;
        }

        System.out.print(result);
    }
}

class Reserve implements Comparable<Reserve> {
    protected int r;
    protected int a;
    protected int n;

    public Reserve(int r, int a, int n) {
        this.r = r;
        this.a = a;
        this.n = n;
    }

    public int getR() {
        return this.r;
    }

    public int getA() {
        return this.a;
    }

    public int getN() { return this.n; }

    @Override
    public int compareTo(Reserve reserve) {
        if (this.a > reserve.a) {
            return 1;
        }
        else if (this.a == reserve.a) {
            if (this.r > reserve.r) {
                return 1;
            }
        }
        return -1;
    }
}