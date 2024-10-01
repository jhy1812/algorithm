import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String S = br.readLine();
        String P = br.readLine();

        int result = 0;
        int i = 0;

        while (i < P.length()) {
            int cnt = 0;
            for (int j = 0; j < S.length(); j++) {
                int tmp = 0;
                if (S.charAt(j) == P.charAt(i)) {
                    tmp++;
                    int k = 1;
                    while (j+k < S.length() && i+k < P.length()) {
                        if (S.charAt(j+k) == P.charAt(i+k)) tmp++;
                        else break;
                        k++;
                    }
                }
                cnt = Math.max(cnt, tmp);
            }

            result++;
            i += cnt;
        }

        System.out.print(result);
    }
}