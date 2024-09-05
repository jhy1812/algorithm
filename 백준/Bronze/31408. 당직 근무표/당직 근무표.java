import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int check = 0;
        int[] lst = new int[100001];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            lst[tmp]++;
            check = Math.max(check, lst[tmp]);
        }

        if (check > (N+1)/2) {
            System.out.print("NO");
        }
        else {
            System.out.print("YES");
        }
    }
}