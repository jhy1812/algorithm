import java.io.*;
import java.util.*;

public class Main {

    static public int N, M, A, B;
    static public long C;
    static public List<List<Node>> arr;
    static public int[] visited;
    static public long[] cost;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Long.parseLong(st.nextToken());

        arr = new ArrayList<>();
        visited = new int[N + 1];
        cost = new long[N + 1];
        Arrays.fill(visited, -1);

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            arr.get(u).add(new Node(v, c));
            arr.get(v).add(new Node(u, c));
        }

        bfs(A);

        System.out.print(visited[B]);
    }

    static private void bfs(int s) {
        PriorityQueue<Node> q = new PriorityQueue<>();
        visited[s] = 0;
        cost[s] = 0;
        q.add(new Node(s, 0));

        while (!q.isEmpty()) {
            Node now = q.poll();
            int nowNum = now.getNum();
            int nowDis = now.getDis();

            if (nowNum == B) {
                return;
            }

            for (Node node : arr.get(nowNum)) {
                int num = node.getNum();
                int dis = node.getDis();
                if (visited[num] == -1) {
                    if (cost[nowNum] + dis <= C) {
                        cost[num] = cost[nowNum] + dis;
                        visited[num] = Math.max(visited[nowNum], dis);
                        q.add(new Node(num, visited[num]));
                    }
                }
                else if (visited[num] > Math.max(visited[nowNum], dis)) {
                    if (cost[nowNum] + dis <= C) {
                        cost[num] = cost[nowNum] + dis;
                        visited[node.getNum()] = Math.max(visited[nowNum], dis);
                        q.add(new Node(num, visited[num]));
                    }
                }
            }
        }
    }
}

class Node implements Comparable<Node> {
    private int num;

    private int dis;

    public Node(int num, int dis) {
        this.num = num;
        this.dis = dis;
    }

    public int getNum() {
        return this.num;
    }

    public int getDis() {
        return this.dis;
    }

    @Override
    public int compareTo(Node node) {
        return this.dis > node.dis ? 1 : -1;
    }
}