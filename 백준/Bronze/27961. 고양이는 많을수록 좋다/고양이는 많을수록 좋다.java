import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long N = Long.parseLong(br.readLine());
        long mul = 1L;
        long result = 1;

        for (int i = 0; i < 60; i++) {
            if (mul >= N) {
                break;
            }
            mul *= 2;
            result++;
        }
        
        if (N == 0) {
            result = 0L;
        }
        
        System.out.print(result);
    }
}