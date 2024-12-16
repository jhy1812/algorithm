import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        bw.write("<");

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        Queue<Integer> q = new LinkedList<>();

        int cnt = 0;

        for (int i = 1; i <= N; i++) {
            q.add(i);
        }

        while(!q.isEmpty()) {
            if ((++cnt)%K == 0) {
                if (q.size() == N) bw.write(String.valueOf(q.poll()));
                else bw.write(", " + q.poll());
            }
            else {
                int tmp = q.poll();
                q.add(tmp);
            }
        }

        bw.write(">");

        br.close();
        bw.flush();
        bw.close();
    }
}