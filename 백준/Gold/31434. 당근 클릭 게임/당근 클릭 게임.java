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

        for (int i = 0; i <= K; i++) {
            Arrays.fill(dp[i], -1);
        }

        dp[0][1] = 0;

        Arrays.sort(click);

        for (int i = 0; i < K; i++) {
            for (int j = 1; j <= 5000; j++) {
                if (dp[i][j] == -1) continue;
                
                dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j] + j);

                for (Pair p : click) {
                    int A = p.getA();
                    int B = p.getB();

                    if (dp[i][j] >= A && j+B <= 5000) {
                        dp[i+1][j+B] = Math.max(dp[i+1][j+B], dp[i][j] - A);
                    }
                    else {
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= 5000; i++) {
            result = Math.max(result, dp[K][i]);
        }

        System.out.print(result);
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