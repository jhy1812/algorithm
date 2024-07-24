import java.io.*;
import java.util.*;

public class Main {
    static private final long MOD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        long num = 1L;
        long result = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'O') {
                result += num;
                result %= MOD;
            }
            num *= 2;
            num %= MOD;
        }

        System.out.print(result);
    }
}