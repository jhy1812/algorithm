import java.io.*;
import java.util.*;

public class Main {

    static private int MOD = 1000000007;
    static private int R, C, K;
    static private int[][] arr;
    static private long[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new int[R][C];
        visited = new long[R][C];

        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                arr[i][j] = tmp;
            }
        }

        long result = dfs(0, 0);

        System.out.print(result);
    }

    private static long dfs(int y, int x) {
        if (visited[y][x] != 0) {
            return visited[y][x] % MOD;
        }

        if (y == R - 1 && x == C - 1) {
            visited[y][x]++;
            return 1L;
        }

        for (int i = y + 1; i < R; i++) {
            for (int j = x + 1; j < C; j++) {
                if (arr[y][x] != arr[i][j]) {
                    visited[y][x] += dfs(i, j);
                    visited[y][x] %= MOD;
                }
            }
        }

        return visited[y][x] % MOD;
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