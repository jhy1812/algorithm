import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int result = 0;

        for (int i = 0; i < 8; i++) {
            String S = br.readLine();

            for (int j = 0; j < 8; j++) {
                if ((i+j)%2 == 0 && S.charAt(j) == 'F') result++;
            }
        }

        System.out.print(result);
    }
}