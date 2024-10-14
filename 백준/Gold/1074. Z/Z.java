import java.io.*;
import java.util.*;

public class Main {

    public static int result = 0;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken()) + 1;
        int c = Integer.parseInt(st.nextToken()) + 1;
        int size = 1;

        for (int i = 0; i < N; i++) {
            size *= 2;
        }

        dfs(size, r, c);

        System.out.print(result);
    }

    public static void dfs(int n, int r, int c) {
        if (n == 1) return;

        if (r <= n/2 && c <= n/2) {
            dfs(n/2, r, c);
        }
        else if (r <= n/2 && c > n/2) {
            result += n*n/4;
            dfs(n/2, r, c - n/2);
        }
        else if (r > n/2 && c <= n/2) {
            result += n*n/2;
            dfs(n/2, r - n/2, c);
        }
        else {
            result += 3*(n*n/4);
            dfs(n/2, r - n/2, c - n/2);
        }
    }
}