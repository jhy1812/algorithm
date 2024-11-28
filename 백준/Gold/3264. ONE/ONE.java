import java.io.*;
import java.util.*;

public class Main {

    public static int N, S, result, ret;
    public static int[] lst;
    public static List<List<Pair>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        result = 0;
        ret = 0;
        lst = new int[N+1];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            arr.get(A).add(new Pair(B, C));
            arr.get(B).add(new Pair(A, C));
            result += 2*C;
        }

        dfs(S, 0);

        System.out.print(result-ret);
    }

    public static void dfs(int cur, int par) {

        for (Pair p : arr.get(cur)) {
            int child = p.getV();
            int d = p.getD();

            if (child == par) continue;
            dfs(child, cur);
            lst[cur] = Math.max(lst[cur], lst[child]+d);
        }

        ret = Math.max(ret, lst[cur]);
    }
}

class Pair {

    private int v;
    private int d;

    public Pair(int v, int d) {
        this.v = v;
        this.d = d;
    }

    public int getV() {
        return this.v;
    }

    public int getD() {
        return this.d;
    }
}