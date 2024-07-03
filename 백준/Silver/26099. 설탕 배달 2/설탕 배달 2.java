import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        long N = Long.parseLong(bf.readLine());
        long result = 0;

        if (N % 5 == 0) {
            result = N / 5;
        }
        else if (N % 5 == 1) {
            result = N / 5 + 1;
        }
        else if (N % 5 == 2) {
            if (N / 5 < 2) {
                result = -1;
            }
            else {
                result = N / 5 + 2;
            }
        }
        else if (N % 5 == 3) {
            result = N / 5 + 1;
        }
        else if (N % 5 == 4) {
            if (N / 5 < 1) {
                result = -1;
            }
            else {
                result = N / 5 + 2;
            }
        }

        System.out.print(result);
    }
}