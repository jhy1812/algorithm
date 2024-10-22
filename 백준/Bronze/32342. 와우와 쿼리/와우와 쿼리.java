import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int Q = Integer.parseInt(br.readLine());

        for (int i = 0; i < Q; i++) {
            int result = 0;
            String S = br.readLine();
            int state = 0;
            for (int j = 0; j < S.length(); j++) {
                if (state == 1 && S.charAt(j) == 'O') state = 2;
                else if (state == 2 && S.charAt(j) == 'W') {
                    result++;
                    state = 1;
                }
                else if (S.charAt(j) == 'W') state = 1;
                else state = 0;
            }

            bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}