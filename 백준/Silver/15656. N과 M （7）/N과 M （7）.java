import java.io.*;
import java.util.*;

public class Main {

    public static BufferedWriter bw;
    public static int N, M;
    public static int[] lst, result;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        lst = new int[N];
        result = new int[M];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            lst[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(lst);

        dfs(0);

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs(int lv) throws IOException {
        if (lv == M) {
            for (int i = 0; i < M; i++) {
                bw.write(result[i] + " ");
            }
            bw.write("\n");
            return;
        }

        for (int i = 0; i < N; i++) {
            result[lv] = lst[i];
            dfs(lv+1);
        }
    }
}