import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String S = br.readLine();
        boolean check = false;

        for (int i = 0; i < N-3; i++) {
            if (S.substring(i, i+4).equals("gori")) {
                check = true;
                break;
            }
        }

        if (check) System.out.print("YES");
        else System.out.print("NO");
    }
}