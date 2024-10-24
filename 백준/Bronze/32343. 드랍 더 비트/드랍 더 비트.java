import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int result = 0;

        for (int i = 0; i < ((a+b <= N) ? a+b : N-Math.max(0, a+b-N)); i++) {
            result += (1 << (N-i-1));
        }

        System.out.print(result);
    }
}