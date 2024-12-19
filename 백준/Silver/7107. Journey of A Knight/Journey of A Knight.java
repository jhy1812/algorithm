import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-2, -1, 1, 2, 2, 1, -1, -2};
    public static int[] dx = {1, 2, 2, 1, -1, -2, -2, -1};
    public static int n, m, ey, ex;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ey = Integer.parseInt(st.nextToken());
        ex = Integer.parseInt(st.nextToken());
        ey--;
        ex--;

        System.out.print(bfs(0, 0));
    }

    public static String bfs(int y, int x) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(y, x));
        int[][] visited = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(visited[i], -1);
        }
        visited[y][x] = 0;

        while (!q.isEmpty()) {
            Pair now = q.poll();
            int yy = now.getY();
            int xx = now.getX();

            if (yy == ey && xx == ex) return String.valueOf(visited[yy][xx]);

            for (int i = 0; i < 8; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                    if (visited[ny][nx] == -1) {
                        visited[ny][nx] = visited[yy][xx] + 1;
                        q.add(new Pair(ny, nx));
                    }
                }
            }
        }

        return "NEVAR";
    }
}

class Pair {
    private int y;
    private int x;

    public Pair(int y, int x) {
        this.y = y;
        this.x = x;
    }

    public int getY() {
        return this.y;
    }

    public int getX() {
        return this.x;
    }
}