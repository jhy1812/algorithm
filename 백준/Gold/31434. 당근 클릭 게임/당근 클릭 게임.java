import java.io.*;
import java.util.*;

public class Main {

    public static int N, K, result;
    public static Pair[] click;
    public static int[][] dp;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        result = 0;

        click = new Pair[N];
        dp = new int[K+1][5001];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            click[i] = new Pair(A, B);
        }

        Arrays.sort(click);

        dfs(0, 1);

        System.out.print(result);
    }

    public static void dfs(int lv, int s) {
        if (lv == K) {
            result = Math.max(result, dp[lv][s]);
            return;
        }
        for (int i = 0; i <= N; i++) {
            if (i == 0) {
                if (dp[lv+1][s] < dp[lv][s]+s || dp[lv+1][s] == 0) {
                    dp[lv+1][s] = dp[lv][s]+s;
                    dfs(lv+1, s);
                }
            }
            else {
                if (click[i-1].getA() <= dp[lv][s]) {
                    if (dp[lv+1][s+click[i-1].getB()] < dp[lv][s]-click[i-1].getA() || dp[lv+1][s+click[i-1].getB()] == 0) {
                        dp[lv+1][s+click[i-1].getB()] = dp[lv][s]-click[i-1].getA();
                        dfs(lv+1, s+click[i-1].getB());
                    }
                }
                else {
                    break;
                }
            }
        }
    }
}

class Pair implements Comparable<Pair>{
    private int a;
    private int b;

    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public int getA() {
        return this.a;
    }

    public int getB() {
        return this.b;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.a > p.getA()) {
            return 1;
        }
        else if (this.a == p.getA()) {
            if (this.b < p.getB()) {
                return 1;
            }
        }
        return -1;
    }
}