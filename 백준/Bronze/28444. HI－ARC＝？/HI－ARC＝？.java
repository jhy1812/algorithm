import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());
        int a = 1;
        int b = 1;

        for (int i = 0; i < 2; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            a *= tmp;
        }

        for (int i = 0; i < 3; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            b *= tmp;
        }

        System.out.print(a - b);
    }
}