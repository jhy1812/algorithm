import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int pkg = 10000;
        int ea = 10000;

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(bf.readLine());
            pkg = Math.min(Integer.parseInt(st.nextToken()), pkg);
            ea = Math.min(Integer.parseInt(st.nextToken()), ea);
        }

        int result = Math.min((N / 6) * pkg + (N % 6) * ea, (N / 6 + 1) * pkg);
        result = Math.min(result, N * ea);
        
        System.out.print(result);
    }
}