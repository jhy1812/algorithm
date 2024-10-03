import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int size = 1 << 15;

        int[] dp = new int[size];

        for (int i = 0; i*i < size; i++) {
            for (int j = i; j*j+i*i < size; j++) {
                for (int k = j; k*k+j*j+i*i < size; k++) {
                    for (int m = k; m*m+k*k+j*j+i*i < size; m++) {
                        dp[m*m+k*k+j*j+i*i]++;
                    }
                }
            }
        }

        while (true) {
            int n = Integer.parseInt(br.readLine());

            if (n == 0) break;

            bw.write(dp[n] + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}