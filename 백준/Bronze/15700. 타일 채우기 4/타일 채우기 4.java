import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        long N = Long.parseLong(st.nextToken());
        long M = Long.parseLong(st.nextToken());

        if (N < M) {
            long tmp = M;
            M = N;
            N = tmp;
        }

        long result;

        if (N % 2 == 0 || M % 2 == 0) {
            result = N * M / 2;
        }
        else {
            result = (N - 1) * M / 2;
            result += M / 2;
        }

        System.out.print(result);
    }
}