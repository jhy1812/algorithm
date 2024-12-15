import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int result = 0;

        for (int i = 1; i < N; i++) {
            int tmp = i;
            int mod = 1;

            while (i / mod != 0) {
                tmp += i % (10 * mod) / mod;
                mod *= 10;
            }

            if (N == tmp) {
                result = i;
                break;
            }
        }

        System.out.print(result);
    }
}