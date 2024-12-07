import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int max = 0;
        int min = 0;
        int[] lst = new int[N];
        st = new StringTokenizer(br.readLine());

        for (int i = 1; i < N; i++) {
            lst[i] = lst[i-1] + Integer.parseInt(st.nextToken());
            max = Math.max(max, lst[i]);
            min = Math.min(min, lst[i]);
        }

        if (max - min == N-1) {
            for (int i = 0; i < N; i++) {
                bw.write((lst[i] - min + 1) + " ");
            }
        }
        else {
            bw.write("-1");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}