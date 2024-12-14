import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> q = new PriorityQueue<>((o1, o2) -> {
            if (Math.abs(o1) > Math.abs(o2)) return 1;
            else if (Math.abs(o1) == Math.abs(o2)) {
                if (o1 > o2) return 1;
            }
            return -1;
        });

        while (N-- > 0) {
            int x = Integer.parseInt(br.readLine());

            if (x == 0) {
                if (q.isEmpty()) bw.write(0 + "\n");
                else bw.write(q.poll() + "\n");
            }
            else q.add(x);
        }

        br.close();
        bw.flush();
        bw.close();
    }
}