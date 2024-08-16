import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-1, 1, 0, 0};
    public static int[] dx = {0, 0, -1, 1};
    public static int n, result;
    public static int[][] forest, visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());

        forest = new int[n][n];
        visited = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                forest[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    result = Math.max(result, dfs(i, j));
                }
            }
        }

        System.out.print(result);
    }

    public static int dfs(int y, int x) {
        if (visited[y][x] != 0) {
            return visited[y][x];
        }

        visited[y][x] = 1;

        int m = 0;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < n && 0 <= nx && nx < n) {
                if (forest[y][x] < forest[ny][nx]) {
                    m = Math.max(m, dfs(ny, nx));
                }
            }
        }

        visited[y][x] += m;
        
        return visited[y][x];
    }
}