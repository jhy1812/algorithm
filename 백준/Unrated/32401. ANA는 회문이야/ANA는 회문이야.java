import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        String S = br.readLine();

        int state = 0;

        for (int i = 0; i < N; i++) {
            if (state == 0 && S.charAt(i) == 'A') {
                state++;
            }
            else if (state == 1 && S.charAt(i) == 'N') {
                state++;
            }
            else if (state == 2 && S.charAt(i) == 'N') {
                state = 0;
            }
            else if (state == 2 && S.charAt(i) == 'A') {
                state = 1;
                result++;
            }
        }

        System.out.print(result);
    }
}