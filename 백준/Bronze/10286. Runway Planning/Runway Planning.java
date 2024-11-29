import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int h = Integer.parseInt(br.readLine());
            int result = 0;
            if (h >= 180) h -= 180;

            if (h%10 >= 5) result = h/10+1;
            else {
                if (h/10 == 0) result = 18;
                else result = h/10;
            }

            if (result/10 == 0) bw.write("0" + result + "\n");
            else bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}