import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            int r = Integer.parseInt(br.readLine());
            if (r == 0) break;

            int result = 0;
            int a = r * r;

            for (int i = 1; i <= r; i++) {
                result += 2 * (int) Math.sqrt(a - i * i) + 1;
            }

            result *= 2;
            result += 2 * r + 1;

            bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}