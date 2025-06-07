import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long MOD = 1000000007L;

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long[] arr = new long[N+1];

        arr[0] = 1;

        for (int i = 1; i <= N; i++) {
            arr[i] += arr[i-1];
            if (i >= M) {
                arr[i] += arr[i-M];
            }
            arr[i] %= MOD;
        }

        bw.write(String.valueOf(arr[N]));

        br.close();
        bw.flush();
        bw.close();
    }
}