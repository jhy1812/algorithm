import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[] weight = new int[N];
        int[] height = new int[N];
        int[] result = new int[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            weight[i] = Integer.parseInt(st.nextToken());
            height[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (weight[j] > weight[i] && height[j] > height[i]) {
                    result[i]++;
                }
            }
            result[i]++;
            bw.write(result[i] + " ");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}