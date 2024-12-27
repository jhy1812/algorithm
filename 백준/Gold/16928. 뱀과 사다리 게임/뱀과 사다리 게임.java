import java.io.*;
import java.util.*;

public class Main {

    public static int[] board, visited;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        board = new int[101];
        visited = new int[101];
        Arrays.fill(visited, -1);

        for (int i = 0;i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            board[x] = y;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            board[u] = v;
        }

        bfs(1);

        System.out.print(visited[100]);
    }

    public static void bfs(int s) {
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        visited[s] = 0;

        while (!q.isEmpty()) {
            int now = q.poll();

            if (board[now] != 0) {
                int next = board[now];
                if (visited[next] == -1 || visited[next] > visited[now]) {
                    visited[next] = visited[now];
                    q.add(next);
                }
            }
            else {
                for (int i = 1; i <= 6; i++) {
                    int next = now+i;
                    if (next > 100) continue;
                    if (visited[next] == -1 || visited[next] > visited[now]+1) {
                        visited[next] = visited[now]+1;
                        q.add(next);
                    }
                }
            }
        }
    }
}