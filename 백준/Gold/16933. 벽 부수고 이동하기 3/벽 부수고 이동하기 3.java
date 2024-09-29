import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};
    public static char wall = '1';
    public static boolean flag = false;
    public static int N, M, K, result;
    public static String[] map;
    public static int[][][] visited;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        result = Integer.MAX_VALUE-1;

        map = new String[N];
        visited = new int[N][M][K+1];

        for (int i = 0; i < N; i++) {
            map[i] = br.readLine();
        }

        bfs(0, 0);

        for (int i = 0; i <= K; i++) {
            if (visited[N-1][M-1][i] == 0) continue;
            flag = true;
            result = Math.min(result, visited[N-1][M-1][i]);
        }

        if (flag) {
            System.out.print(result);
        }
        else {
            System.out.print(-1);
        }
    }

    public static void bfs(int y, int x) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(y, x, 0));
        visited[y][x][0] = 1;

        while (!q.isEmpty()) {
            Pair now = q.poll();
            int yy = now.getY();
            int xx = now.getX();
            int num = now.getN();

            for (int i = 0; i < 4; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                    if (map[ny].charAt(nx) == wall && num < K) {
                        if (visited[yy][xx][num]%2 == 1) {
                            if (visited[ny][nx][num+1] == 0 || visited[ny][nx][num+1] > visited[yy][xx][num] + 1) {
                                visited[ny][nx][num+1] = visited[yy][xx][num] + 1;
                                q.add(new Pair(ny, nx, num+1));
                            }
                        }
                        else {
                            if (visited[ny][nx][num+1] == 0 || visited[ny][nx][num+1] > visited[yy][xx][num] + 2) {
                                visited[ny][nx][num+1] = visited[yy][xx][num] + 2;
                                q.add(new Pair(ny, nx, num+1));
                            }
                        }
                    }
                    else if (map[ny].charAt(nx) != wall) {
                        if (visited[ny][nx][num] == 0 || visited[ny][nx][num] > visited[yy][xx][num] + 1) {
                            visited[ny][nx][num] = visited[yy][xx][num] + 1;
                            q.add(new Pair(ny, nx, num));
                        }
                    }
                }
            }
        }
    }
}

class Pair {
    private int y;
    private int x;
    private int n;

    public Pair(int y, int x, int n) {
        this.y = y;
        this.x = x;
        this.n = n;
    }

    public int getY() {
        return this.y;
    }

    public int getX() {
        return this.x;
    }

    public int getN() {
        return this.n;
    }
}