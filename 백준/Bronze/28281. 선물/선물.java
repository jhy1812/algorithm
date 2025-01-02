import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int result = 2000000001;
        int[] lst = new int[2];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            lst[i%2] = Integer.parseInt(st.nextToken());
            if (i == 0) continue;
            result = Math.min(result, lst[0]+lst[1]);
        }

        System.out.print(result*X);
    }
}