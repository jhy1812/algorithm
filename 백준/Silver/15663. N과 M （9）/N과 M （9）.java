import java.io.*;
import java.util.*;

public class Main {

    public static BufferedWriter bw;
    public static int N, M;
    public static int[] result, check;
    public static List<Integer> lst;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        result = new int[M];
        check = new int[10001];
        lst = new ArrayList<>();

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            if (check[tmp] == 0) lst.add(tmp);
            if (check[tmp] == M) continue;
            check[tmp]++;
        }

        Collections.sort(lst);

        dfs(0);

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs(int lv) throws IOException{
        if (lv == M) {
            for (int i = 0; i < M; i++) bw.write(result[i] + " ");
            bw.write("\n");
            return;
        }

        for (int i = 0; i < lst.size(); i++) {
            if (check[lst.get(i)] > 0) {
                check[lst.get(i)]--;
                result[lv] = lst.get(i);
                dfs(lv+1);
                check[lst.get(i)]++;
            }
        }
    }
}