import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String X = br.readLine();
        int x = 0;
        int cnt = 1;

        if (X.length() == 1) {
            x = Integer.parseInt(X);

            if (x%3 == 0) bw.write(0 + "\nYES");
            else bw.write(0 + "\nNO");
        }
        else {
            for (int i = 0; i < X.length(); i++) {
                x += (X.charAt(i)-'0');
            }
            while (true) {
                if (x/10 == 0) break;
                int mod = 1;
                int tmp = 0;
                cnt++;
                while (true) {
                    if (x/mod == 0) break;
                    tmp += (x%(10*mod))/mod;
                    mod *= 10;
                }
                x = tmp;
            }

            if (x%3 == 0) bw.write(cnt + "\nYES");
            else bw.write(cnt + "\nNO");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}