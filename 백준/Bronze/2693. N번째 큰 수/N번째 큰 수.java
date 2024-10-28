import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());

            for (int i = 0; i < 10; i++) q.add(Integer.parseInt(st.nextToken()));

            q.poll();
            q.poll();

            bw.write(q.poll() + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}