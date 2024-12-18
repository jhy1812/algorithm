import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};
    public static int result;
    public static int[][] board;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        result = 0;
        board = new int[5][5];

        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());

        int sr = Integer.parseInt(st.nextToken());
        int sc = Integer.parseInt(st.nextToken());

        if (bfs(sr, sc)) System.out.print(result);
        else System.out.print(-1);
    }

    public static boolean bfs(int r, int c) {
        int y = r;
        int x = c;
        for (int i = 1; i <= 6; i++) {
            Queue<Pair> q = new LinkedList<>();
            q.add(new Pair(y, x));
            int[][] visited = new int[5][5];
            boolean check = false;
            for (int j = 0; j < 5; j++) Arrays.fill(visited[j], -1);
            visited[y][x] = 0;
            while (!q.isEmpty()) {
                Pair now = q.poll();
                int yy = now.getY();
                int xx = now .getX();

                if (board[yy][xx] == i) {
                    check = true;
                    result += visited[yy][xx];
                    y = yy;
                    x = xx;
                    break;
                }

                for (int j = 0; j < 4; j++) {
                    int ny = yy + dy[j];
                    int nx = xx + dx[j];

                    if (0 <= ny && ny < 5 && 0 <= nx && nx < 5) {
                        if (visited[ny][nx] == -1 && board[ny][nx] != -1) {
                            visited[ny][nx] = visited[yy][xx] + 1;
                            q.add(new Pair(ny, nx));
                        }
                    }
                }
            }

            if (!check) return false;
        }
        return true;
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