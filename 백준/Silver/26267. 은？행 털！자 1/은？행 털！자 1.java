import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        long result = 0L;
        HashMap<Integer, Long> lst = new HashMap<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken());
            int T = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            if (!lst.containsKey(X-T)) {
                lst.put(X-T, (long) C);
                result = Math.max(result, (long) C);
            }
            else {
                long tmp = lst.get(X-T);
                tmp += (long) C;
                lst.replace(X-T, tmp);
                result = Math.max(result, tmp);
            }
        }

        System.out.print(result);
    }
}