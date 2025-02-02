import java.io.*;
import java.util.*;

public class Main {

    public static int N, result;
    public static int[] du, we;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        du = new int[N];
        we = new int[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            du[i] = Integer.parseInt(st.nextToken());
            we[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0);

        System.out.print(result);
    }

    public static void dfs(int lv) {
        if (lv == N) {
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (du[i] <= 0) cnt++;
            }
            result = Math.max(result, cnt);
            return;
        }

        boolean check = false;
        for (int i = 0; i < N; i++) {
            if (i == lv) continue;
            if (du[lv] > 0 && du[i] > 0) {
                du[lv] -= we[i];
                du[i] -= we[lv];
                dfs(lv+1);
                du[lv] += we[i];
                du[i] += we[lv];
                check = true;
            }
        }

        if (!check) dfs(lv+1);
    }
}