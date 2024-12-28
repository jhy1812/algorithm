import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        boolean[] lst = new boolean[N+1];
        int result = 0;
        int cnt = 0;

        for (int i = 2; i <= N; i++) {
            if (lst[i]) continue;
            for (int j = i; j <= N; j+=i) {
                if (!lst[j]) {
                    lst[j] = true;
                    cnt++;
                }
                if (cnt == K) {
                    result = j;
                    break;
                }
            }
            if (cnt == K) break;
        }

        System.out.print(result);
    }
}