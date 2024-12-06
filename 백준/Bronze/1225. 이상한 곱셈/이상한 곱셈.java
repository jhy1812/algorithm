import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String A = st.nextToken();
        String B = st.nextToken();

        int[] a = new int[10];
        int[] b = new int[10];

        for (int i = 0; i < A.length(); i++) a[A.charAt(i) - '0']++;
        for (int i = 0; i < B.length(); i++) b[B.charAt(i) - '0']++;

        long result = 0;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                result += (long) (i*j) * (a[i]*b[j]);
            }
        }

        System.out.print(result);
    }
}