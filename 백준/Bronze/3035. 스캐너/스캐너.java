import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int ZR = Integer.parseInt(st.nextToken());
        int ZC = Integer.parseInt(st.nextToken());

        for (int i = 0; i < R; i++) {
            String tmp = br.readLine();
            String S = "";
            for (int j = 0; j < C; j++) {
                for (int k = 0; k < ZC; k++) {
                    S += tmp.charAt(j);
                }
            }

            for (int j = 0; j < ZR; j++) {
                bw.write(S + "\n");
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}