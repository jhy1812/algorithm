import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long N = Long.parseLong(br.readLine());
        int flag = 0;
        if (N == 0L) {
            System.out.print("NO");
            flag = 1;
        }

        long[] sam = new long[40];
        sam[0] = 1;
        for (int i = 1; i <40; i++) {
            sam[i] = sam[i - 1] * 3;
        }

        for (int i = 39; i >= 0; i--) {
            if (N >= sam[i]) {
                N -= sam[i];
            }
        }

        if (N == 0L && flag == 0) {
            System.out.print("YES");
        }
        else if (flag == 0) {
            System.out.print("NO");
        }
    }
}