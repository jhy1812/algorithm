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
            int result = Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken());
            bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}