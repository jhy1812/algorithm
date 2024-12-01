import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int Q = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= Q; tc++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (a < b) {
                if (b-a < 22) bw.write("Inner circle line\n");
                else bw.write("Outer circle line\n");
            }
            else {
                if (a-b < 22) bw.write("Outer circle line\n");
                else bw.write("Inner circle line\n");
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}