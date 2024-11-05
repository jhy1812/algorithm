import java.io.*;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int X = Integer.parseInt(br.readLine());
        int stick = 64;
        int result = 0;

        while (stick > 0) {
            if ((stick & X) != 0) result++;
            stick /= 2;
        }

        System.out.print(result);
    }
}