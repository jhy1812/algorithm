import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            String N = br.readLine();
            if (N.charAt(0) == '0') {
                break;
            }
            int result = N.length() + 1;

            for (int i = 0; i < N.length(); i++) {
                if (N.charAt(i) == '0') {
                    result += 4;
                }
                else if (N.charAt(i) == '1') {
                    result += 2;
                }
                else {
                    result += 3;
                }
            }

            bw.write(result + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}