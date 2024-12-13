import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};
    public static int N, M;
    public static boolean[][] visited;
    public static String[] camp;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new boolean[N][M];
        camp = new String[N];
        int result = 0;

        for (int i = 0; i < N; i++) {
            camp[i] = br.readLine();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (camp[i].charAt(j) == 'I') {
                    result = bfs(i, j);
                    break;
                }
            }
        }

        if (result == 0) System.out.print("TT");
        else System.out.print(result);
    }

    public static int bfs(int y, int x) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(y, x));
        visited[y][x] = true;
        int cnt = 0;
        while (!q.isEmpty()) {
            Pair now = q.poll();
            int yy = now.getY();
            int xx = now.getX();

            for (int i = 0; i < 4; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                    if (!visited[ny][nx] && camp[ny].charAt(nx) != 'X') {
                        visited[ny][nx] = true;
                        if (camp[ny].charAt(nx) == 'P') cnt++;
                        q.add(new Pair(ny, nx));
                    }
                }
            }
        }

        return cnt;
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