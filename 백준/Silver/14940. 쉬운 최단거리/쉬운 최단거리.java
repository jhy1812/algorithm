import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};
    public static int n, m;
    public static int[][] map, visited;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        visited = new int[n][m];

        int sy = 0;
        int sx = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            Arrays.fill(visited[i], -1);
            for (int j = 0; j < m; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                map[i][j] = tmp;

                if (tmp == 0) visited[i][j] = 0;
                if (tmp == 2) {
                    sy = i;
                    sx = j;
                }
            }
        }

        bfs(sy, sx);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bw.write(visited[i][j] + " ");
            }
            bw.write("\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void bfs(int y, int x) {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(y, x));
        visited[y][x] = 0;

        while (!q.isEmpty()) {
            Node N = q.poll();
            int yy = N.getY();
            int xx = N.getX();

            for (int i = 0; i < 4; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                    if (visited[ny][nx] == -1 && map[ny][nx] == 1) {
                        visited[ny][nx] = visited[yy][xx] + 1;
                        q.add(new Node(ny, nx));
                    }
                }
            }
        }
    }
}

class Node {
    private int y;
    private int x;

    public Node(int y, int x) {
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