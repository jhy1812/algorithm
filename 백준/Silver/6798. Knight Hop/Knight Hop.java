import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-2, -2, -1, 1, 2, 2, 1, -1};
    public static int[] dx = {-1, 1, 2, 2, 1, -1, -2, -2};

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int sy = Integer.parseInt(st.nextToken());
        int sx = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int ey = Integer.parseInt(st.nextToken());
        int ex = Integer.parseInt(st.nextToken());

        System.out.print(bfs(sy-1, sx-1, ey-1, ex-1));
    }

    public static int bfs(int sy, int sx, int ey, int ex) {
        int[][] visited = new int[8][8];
        Queue<Pair> q = new LinkedList<>();

        for (int i = 0; i < 8; i++) Arrays.fill(visited[i], -1);

        visited[sy][sx] = 0;
        q.add(new Pair(sy, sx));

        while(!q.isEmpty()) {
            Pair now = q.poll();
            int yy = now.getY();
            int xx = now.getX();

            if (yy == ey && xx == ex) return visited[yy][xx];

            for (int i = 0; i < 8; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < 8 && 0 <= nx && nx < 8) {
                    if (visited[ny][nx] == -1) {
                        visited[ny][nx] = visited[yy][xx] + 1;
                        q.add(new Pair(ny, nx));
                    }
                }
            }
        }

        return 0;
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