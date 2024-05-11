import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());
        HashMap<Integer, Integer> check = new HashMap<>();

        StringTokenizer st = new StringTokenizer(bf.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            check.put(tmp, check.getOrDefault(tmp, 0) + 1);
        }

        int M = Integer.parseInt(bf.readLine());
        st = new StringTokenizer(bf.readLine());

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            sb.append(check.getOrDefault(tmp, 0)).append(" ");
        }
        
        System.out.print(sb.toString());
    }
}
