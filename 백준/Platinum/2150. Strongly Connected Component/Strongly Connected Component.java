import java.io.*;
import java.util.*;

public class Main {

    public static int V, E;
    public static boolean[] comp;
    public static int[] visited;
    public static List<List<Integer>> fr, ba, result;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        comp = new boolean[V+1];
        visited = new int[V+1];

        fr = new ArrayList<>();
        ba = new ArrayList<>();
        result = new ArrayList<>();

        for (int i = 0; i <= V; i++) {
            fr.add(new ArrayList<>());
            ba.add(new ArrayList<>());
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            fr.get(A).add(B);
            ba.get(B).add(A);
        }

        int cnt = 0;

        for (int i = 1; i <= V; i++) {
            if (comp[i]) continue;
            Arrays.fill(visited, 0);
            result.add(new ArrayList<>());

            dfs1(i, i);
            dfs2(i, i);

            for (int j = i; j <= V; j++) {
                if (visited[j] == 2) {
                    comp[j] = true;
                    result.get(cnt).add(j);
                }
            }
            cnt++;
        }

        bw.write(cnt + "\n");

        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < result.get(i).size(); j++) {
                bw.write(result.get(i).get(j) + " ");
            }
            bw.write(-1 + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs1(int n, int lim) {
        visited[n]++;

        for (int next : fr.get(n)) {
            if (visited[next] != 0 || next < lim || comp[next]) continue;
            dfs1(next, lim);
        }
    }

    public static void dfs2(int n, int lim) {
        visited[n]++;

        for (int next : ba.get(n)) {
            if (visited[next] != 1 || next < lim || comp[next]) continue;
            dfs2(next, lim);
        }
    }
}