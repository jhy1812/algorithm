import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int result = N;
        int[] arr = new int[N];
        int[] dp = new int[N];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            dp[i] = Math.max(dp[i], dp[Math.max(0, i-1)]);
            int rock = arr[i];
            for (int j = i+1; j < N; j++) {
                if (rock > arr[j]) {
                    break;
                }
                else if (rock == arr[j]) {
                    dp[j] = Math.max(dp[j], dp[Math.max(0, i-1)]+1);
                    break;
                }
                else {
                    rock = arr[j] - rock;
                }
            }
        }

        System.out.print(result - dp[N-1]);
    }
}