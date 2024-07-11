import java.io.*;
import java.util.*;

public class Main {

    static public int N;
    static public int[] dy = {-2, -2, -1, -1, 1, 1, 2, 2};
    static public int[] dx = {-1, 1, -2, 2, -2, 2, -1, 1};
    static public int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            int r1 = Integer.parseInt(st.nextToken());
            int c1 = Integer.parseInt(st.nextToken());
            int r2 = Integer.parseInt(st.nextToken());
            int c2 = Integer.parseInt(st.nextToken());

            board = new int[N + 1][N + 1];
            for (int i = 1; i <= N; i++) {
                Arrays.fill(board[i], -1);
            }

            bfs(r1, c1, r2, c2);

            System.out.println("Case #" + tc + ": " + board[r2][c2] + "\n");
        }
    }

    static private void bfs(int r1, int c1, int r2, int c2) {
        board[r1][c1] = 0;
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(r1, c1));
        while (!q.isEmpty()) {
            Node now = q.poll();
            int nowY = now.getY();
            int nowX = now.getX();
            if (nowY == r2 && nowX == c2) {
                return;
            }
            for (int i = 0; i < 8; i++) {
                int ny = nowY + dy[i];
                int nx = nowX + dx[i];
                if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
                    if (board[ny][nx] == -1) {
                        board[ny][nx] = board[nowY][nowX] + 1;
                        q.add(new Node(ny, nx));
                    }

                }
            }
        }
    }
}

class Node {
    private int x;
    private int y;

    public Node(int y, int x) {
        this.y = y;
        this.x = x;
    }

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }
}