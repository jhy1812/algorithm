import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String S = br.readLine();
        int l = S.length()%3;
        int mod = (l+2)%3;
        int tmp = 0;
        for (int i = 0; i < S.length(); i++) {
            if (i%3 == mod) {
                if (S.charAt(i) == '1') tmp++;
                bw.write(String.valueOf(tmp));
                tmp = 0;
            }
            else if (i%3 == (mod+1)%3) {
                if (S.charAt(i) == '1') tmp += 4;
            }
            else {
                if (S.charAt(i) == '1') tmp += 2;
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}