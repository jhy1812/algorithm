import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        while(true) {
            int num = Integer.parseInt(br.readLine());

            if (num == 0) break;

            if (num%n == 0) bw.write(num + " is a multiple of " + n + ".\n");
            else bw.write(num + " is NOT a multiple of " + n + ".\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}