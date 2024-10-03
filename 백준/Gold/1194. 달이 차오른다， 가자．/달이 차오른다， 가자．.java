import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};
    public static int N, M, result;
    public static char[][] maze;
    public static int[][] dp, visited;
    public static HashMap<Character, Integer> key, door;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int sy = 0;
        int sx = 0;
        result = -1;

        maze = new char[N][M];
        dp = new int[N][M];
        visited = new int[N][M];
        key = new HashMap<>();
        door = new HashMap<>();

        key.put('a', 1);
        key.put('b', 2);
        key.put('c', 3);
        key.put('d', 4);
        key.put('e', 5);
        key.put('f', 6);

        door.put('A', 1);
        door.put('B', 2);
        door.put('C', 3);
        door.put('D', 4);
        door.put('E', 5);
        door.put('F', 6);

        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            Arrays.fill(visited[i], -1);
            for (int j = 0; j < M; j++) {
                maze[i][j] = tmp.charAt(j);
                if (maze[i][j] == '0') {
                    sy = i;
                    sx = j;
                }
            }
        }

        bfs(sy, sx);

        System.out.print(result);
    }

    public static void bfs(int y, int x) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(y, x, 1));
        visited[y][x] = 0;
        dp[y][x] = 1;

        while (!q.isEmpty()) {
            Pair now = q.poll();
            int yy = now.getY();
            int xx = now.getX();
            int ss = now.getS();

            for (int i = 0; i < 4; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                    if ((dp[ny][nx] & ss) != ss) {
                        if (maze[ny][nx] == '.' || maze[ny][nx] == '0') {
                            visited[ny][nx] = visited[yy][xx] + 1;
                            dp[ny][nx] = ss;
                            q.add(new Pair(ny, nx, dp[ny][nx]));
                        }
                        else if (maze[ny][nx] == '1') {
                            result = visited[yy][xx]+1;
                            return;
                        }
                        else if (0 <= maze[ny][nx]-'a' && maze[ny][nx]-'a' <=5) {
                            visited[ny][nx] = visited[yy][xx] + 1;
                            dp[ny][nx] = ss | (1 << key.get(maze[ny][nx]));
                            q.add(new Pair(ny, nx, dp[ny][nx]));
                        }
                        else if (maze[ny][nx] != '#') {
                            if (((1 << door.get(maze[ny][nx])) & ss) != 0) {
                                visited[ny][nx] = visited[yy][xx] + 1;
                                dp[ny][nx] = ss;
                                q.add(new Pair(ny, nx, dp[ny][nx]));
                            }
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
    private int s;

    public Pair(int y, int x, int s) {
        this.y = y;
        this.x = x;
        this.s = s;
    }

    public int getY() {
        return this.y;
    }

    public int getX() {
        return this.x;
    }

    public int getS() {
        return this.s;
    }
}