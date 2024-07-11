import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] medicine = new int[101];
        Arrays.fill(medicine, -1);
        StringTokenizer st;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int e = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            medicine[e] = n;
        }

        int R = Integer.parseInt(br.readLine());
        int[] pre;
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            pre = new int[L];
            int flag = 0;
            for (int j = 0; j < L; j++) {
                int s = Integer.parseInt(st.nextToken());
                if (medicine[s] == -1) {
                    flag = 1;
                    break;
                }
                pre[j] = medicine[s];
            }

            if (flag == 1) {
                System.out.println("YOU DIED");
            }
            else {
                for (int j = 0; j < L; j++) {
                    System.out.print(pre[j] + " ");
                }
                System.out.println();
            }
        }
    }
}