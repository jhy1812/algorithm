import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int result = 0;

        while(true) {
            int n = Integer.parseInt(br.readLine());

            if (n == -1) break;

            result += n;
        }

        System.out.print(result);
    }
}