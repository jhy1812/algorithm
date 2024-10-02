import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy, dx, cy, cx, ry, rx;
    public static int N, M, H, W, Sr, Sc, Fr, Fc;
    public static boolean[][] board;
    public static int[][] visited;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new boolean[N][M];
        visited = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            Arrays.fill(visited[i], -1);
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken()) == 0;
            }
        }

        st = new StringTokenizer(br.readLine());

        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        Sr = Integer.parseInt(st.nextToken())-1;
        Sc = Integer.parseInt(st.nextToken())-1;

        Fr = Integer.parseInt(st.nextToken())-1;
        Fc = Integer.parseInt(st.nextToken())-1;

        dy = new int[]{-1, 0, H, 0};
        dx = new int[]{0, W, 0, -1};

        cy = new int[]{0, 1, 0, 1};
        cx = new int[]{1, 0, 1, 0};

        ry = new int[]{-1, 0, 1, 0};
        rx = new int[]{0, 1, 0, -1};

        System.out.print(bfs(Sr, Sc));
    }

    public static int bfs(int y, int x) {
        visited[y][x] = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(y, x));

        while (!q.isEmpty()) {
            Pair now = q.poll();
            int yy = now.getY();
            int xx = now.getX();

            if (yy == Fr && xx == Fc) return visited[yy][xx];

            for (int i = 0; i < 4; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                    if (visited[yy+ry[i]][xx+rx[i]] != -1) continue;
                    if (!board[ny][nx]) continue;
                    boolean check = true;
                    for (int j = 1; j < (i%2 == 0 ? W : H); j++) {
                        ny += cy[i];
                        nx += cx[i];
                        if (!board[ny][nx]) {
                            check = false;
                            break;
                        }
                    }
                    if (check) {
                        ny = yy + ry[i];
                        nx = xx + rx[i];
                        visited[ny][nx] = visited[yy][xx] + 1;
                        q.add(new Pair(ny, nx));
                    }
                }
            }
        }

        return -1;
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