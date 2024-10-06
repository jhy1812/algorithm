import java.io.*;
import java.util.*;

public class Main {

    public static int N, result;
    public static boolean visited[];
    public static int[] arr, path;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        result = 0;
        visited = new boolean[N];
        arr = new int[N];
        path = new int[N+1];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0);

        System.out.print(result);
    }

    public static void dfs(int lv) {
        if (lv == N) {
            int cnt = 0;
            for (int i = 0; i <= N; i++) {
                for (int j = 1; j <= N; j++ ) {
                    if (path[j]-path[i] == 50) {
                        if (j == N) break;
                        cnt++;
                    }
                }
            }

            result = Math.max(result, cnt);
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                path[lv+1] = path[lv] + arr[i];
                dfs(lv+1);
                visited[i] = false;
            }
        }
    }
}