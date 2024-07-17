import java.io.*;
import java.util.*;

public class Main {
    static private int[] dy = {-1, -1, 0, 0, 1, 1};
    static private int[][] dx = {{-1, 0, -1, 1, -1, 0}, {0, 1, -1, 1, 0, 1}};
    static private int N, M, K;
    static private int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new int[N][M];

        for (int i = 0; i < N; i++) {
            Arrays.fill(arr[i], -1);
        }

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            arr[y][x] = -2;
        }

        bfs(0, 0);
        System.out.print(arr[N - 1][M - 1]);
    }

    static private void bfs(int y, int x) {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(y, x));
        arr[y][x] = 0;
        while (!q.isEmpty()) {
            Node now = q.poll();
            y = now.getY();
            x = now.getX();

            if (y == N - 1 && x == M - 1) {
                return;
            }

            for (int i = 0; i < 6; i++) {
                int ny = y + dy[i];
                int nx = x + dx[y%2][i];

                if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                    if (arr[ny][nx] == -1) {
                        arr[ny][nx] = arr[y][x] + 1;
                        q.add(new Node(ny, nx));
                    }
                }
            }
        }
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