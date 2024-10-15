import java.io.*;
import java.util.*;

public class Main {

    public static int V, E, P;
    public static int[] visited;
    public static List<List<Pair>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        visited = new int[V+1];
        arr = new ArrayList<>();


        for (int i = 0; i <= V; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            arr.get(a).add(new Pair(b, c));
            arr.get(b).add(new Pair(a, c));
        }

        bfs(1);

        int dis1 = visited[V];

        bfs(P);

        int dis2 = visited[1] + visited[V];

        if (dis1 >= dis2) System.out.print("SAVE HIM");
        else System.out.print("GOOD BYE");
    }

    public static void bfs(int s) {
        PriorityQueue<Pair> q = new PriorityQueue<>();
        q.add(new Pair(s, 0));
        Arrays.fill(visited, -1);
        visited[s] = 0;

        while (!q.isEmpty()) {
            Pair now = q.poll();
            int cur = now.getV();

            for (Pair p : arr.get(cur)) {
                int v = p.getV();
                int d = p.getD();
                if (visited[v] == -1 || visited[v] > visited[cur]+d) {
                    visited[v] = visited[cur] + d;
                    q.add(new Pair(v, visited[v]));
                }
            }
        }
    }
}

class Pair implements Comparable<Pair> {
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

    @Override
    public int compareTo(Pair p) {
        if (this.d > p.getD()) return 1;
        return -1;
    }
}