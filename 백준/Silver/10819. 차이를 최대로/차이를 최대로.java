import java.io.*;
import java.util.*;

public class Main {

    public static int N, result;
    public static int[] arr, path;
    public static boolean[] check;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        result = 0;
        arr = new int[N];
        path = new int[N];
        check = new boolean[N];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0, 0);

        System.out.print(result);
    }

    public static void dfs(int lv, int sum) {
        if (lv == N) {
            result = Math.max(result, sum);
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!check[i]) {
                check[i] = true;
                path[lv] = arr[i];
                if (lv > 0) {
                    dfs(lv+1, sum+Math.abs(path[lv]-path[lv-1]));
                }
                else {
                    dfs(lv+1, sum);
                }
                check[i] = false;
            }
        }
    }
}