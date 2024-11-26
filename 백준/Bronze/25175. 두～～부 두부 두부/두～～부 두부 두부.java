import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        K += 100000 - 100000%N;
        K += N;

        if (K > 3) {
            int result = (M+K-3)%N;
            if (result == 0) result = N;
            System.out.print(result);
        }
        else if (K < 3) {

            int result = (M+K-3)%N;
            if (result == 0) result = N;
            System.out.print(result);
        }
        else System.out.print(M);
    }
}