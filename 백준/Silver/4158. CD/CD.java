import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int result = 0;
            HashMap<Integer, Boolean> check = new HashMap<>();

            if (N == 0 && M == 0) break;

            for (int i = 0; i < N; i++) {
                check.put(Integer.parseInt(br.readLine()), true);
            }

            for (int i = 0; i < M; i++) {
                if (check.containsKey(Integer.parseInt(br.readLine()))) result++;
            }
            bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}