import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, R, seq;
    public static long result;
    public static int[] lev;
    public static List<List<Integer>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        seq = 0;
        lev = new int[N+1];
        arr = new ArrayList<>();

        Arrays.fill(lev, -1);

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            arr.get(u).add(v);
            arr.get(v).add(u);
        }

        for (int i = 1; i <= N; i++) {
            Collections.sort(arr.get(i));
        }

        dfs(0, R);

        System.out.print(result);
    }

    public static void dfs(int lv, int cur) {
        lev[cur] = lv;
        result += (long) lv*(++seq);

        for (int child : arr.get(cur)) {
            if (lev[child] == -1) {
                dfs(lv+1, child);
            }
        }
    }
}