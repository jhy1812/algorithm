import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] dp = new int[10001];
        int[] me = new int[N];
        int[] co = new int[N];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            me[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            co[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            for (int j = 10000-co[i]; j >= 0; j--) {
                if (dp[j] == 0 && j > 0) continue;
                dp[j+co[i]] = Math.max(dp[j+co[i]], dp[j] + me[i]);
            }
        }

        for (int i = 0; i <=10000; i++) {
            if (dp[i] >= M) {
                System.out.print(i);
                break;
            }
        }
    }
}