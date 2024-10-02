import java.io.*;
import java.util.*;

public class Main {

    public static int N, result;
    public static int[] arr, dp;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        result = N - 1;
        arr = new int[N];
        dp = new int[N*(N+1)/2];
        Arrays.fill(dp, Integer.MAX_VALUE);
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j + i < N; j++) {
                int idx = calcIdx(j, i);
                if (i == 0) {
                    dp[idx] = 0;
                    continue;
                }

                if (arr[j] == arr[j+i]) {
                    if (i == 1) dp[idx] = 0;
                    else {
                        dp[idx] = Math.min(dp[idx], dp[calcIdx(j+1, i-2)]);
                    }
                }
                else {
                    dp[idx] = Math.min(dp[idx], dp[calcIdx(j+1, i-1)]+1);
                    dp[idx] = Math.min(dp[idx], dp[calcIdx(j, i-1)]+1);
                }
            }
        }

        System.out.print(dp[calcIdx(0, N-1)]);
    }

    public static int calcIdx(int left, int right) {
        return left*(2*N + (left-1)*(-1))/2 + right;
    }
}