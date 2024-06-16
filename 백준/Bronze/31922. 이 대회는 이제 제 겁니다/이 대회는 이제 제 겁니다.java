import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        int a = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        if (a + c > p) {
            System.out.print(a + c);
        }
        else {
            System.out.print(p);
        }
    }
}