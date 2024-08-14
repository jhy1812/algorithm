import java.io.*;
import java.util.*;

public class Main {
    public static int[] dy = {0, -1, 0, 1};
    public static int[] dx = {-1, 0, 1, 0};
    public static int N, M, maxArea, MaxArea;
    public static int[][] castle, visited;
    public static List<Integer> area;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        castle = new int[N][M];
        visited = new int[N][M];
        area = new ArrayList<>();
        maxArea = 0;
        MaxArea = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            Arrays.fill(visited[i], -1);
            for (int j = 0; j < M; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                castle[i][j] = tmp;
            }
        }

        int count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == -1) {
                    area.add(bfs(i, j, count++));
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 2; k < 4; k++) {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if (0 <= y && y < N && 0 <= x && x < M) {
                        if (visited[i][j] != visited[y][x]) {
                            MaxArea = Math.max(MaxArea, area.get(visited[i][j]) + area.get(visited[y][x]));
                        }
                    }
                }
            }
        }

        if (MaxArea == 0) {
            MaxArea = maxArea;
        }

        System.out.print(count + "\n" + maxArea + "\n" + MaxArea);
    }

    private static int bfs(int y, int x, int num) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(y, x));
        visited[y][x] = num;
        int a = 1;
        while(!q.isEmpty()) {
            Pair p = q.poll();
            y = p.getY();
            x = p.getX();

            for (int i = 0; i < 4; i++) {
                if ((castle[y][x] & (1 << i)) == 0) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                        if (visited[ny][nx] == -1) {
                            visited[ny][nx] = num;
                            a++;
                            q.add(new Pair(ny, nx));
                        }
                    }
                }
            }
        }
        maxArea = Math.max(maxArea, a);
        return a;
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