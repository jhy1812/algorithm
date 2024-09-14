import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String S = br.readLine();
        boolean ret = false;

        int x = 1;

        while (true) {
            if (x+4 > S.length()) {
                break;
            }
            boolean flag = true;
            for (int i = x; i < x+4; i++) {
                if (Math.abs(S.charAt(i) - S.charAt(i-1)) != 1) {
                    flag = false;
                    x = i+1;
                    break;
                }
            }
            if (flag) {
                ret = true;
                break;
            }
        }

        if (ret) {
            System.out.print("YES");
        }
        else {
            System.out.print("NO");
        }
    }
}