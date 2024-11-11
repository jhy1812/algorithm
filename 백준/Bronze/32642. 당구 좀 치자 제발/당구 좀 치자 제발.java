import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        long result = 0;
        int ang = 0;
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            ang = Integer.parseInt(st.nextToken()) == 0 ? --ang : ++ang;
            result += ang;
        }

        System.out.print(result);
    }
}