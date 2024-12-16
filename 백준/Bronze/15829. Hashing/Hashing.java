import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int L = Integer.parseInt(br.readLine());
        long mod = 1234567891L;
        long r = 1L;
        long result = 0L;
        String S = br.readLine();

        for (int i = 0; i < L; i++) {
            result += (long) (S.charAt(i) - 'a' + 1) * r;
            r *= 31L;
            result %= mod;
            r %= mod;
        }

        System.out.print(result);
    }
}