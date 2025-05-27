import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};
    public static int N, M, A, B, K;
    public static int[][] map;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new int[N][M];

        for (int i = 0; i < N; i++) Arrays.fill(map[i], -1);

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            map[y-1][x-1] = -2;
        }

        st = new StringTokenizer(br.readLine());

        int sy = Integer.parseInt(st.nextToken());
        int sx = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int ey = Integer.parseInt(st.nextToken());
        int ex = Integer.parseInt(st.nextToken());

        if (map[ey-1][ex-1] == -2) System.out.print(-1);
        else {
            solve(sy-1, sx-1);
            System.out.print(map[ey-1][ex-1]);
        }
    }

    public static void solve(int y, int x) {
        Queue<Pair> q = new LinkedList<>();
        map[y][x] = 0;
        q.add(new Pair(y, x));

        while (!q.isEmpty()) {
            Pair now = q.poll();
            y = now.getY();
            x = now.getX();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (0 <= ny && ny <= N-A && 0 <= nx && nx <= M-B) {
                    if (map[ny][nx] == -1) {
                        boolean check = true;
                        if (i == 0) {
                            for (int j = 0; j < B; j++) {
                                if (map[ny][nx+j] == -2) {
                                    check = false;
                                    break;
                                }
                            }
                        }
                        else if (i == 1) {
                            for (int j = 0; j < A; j++) {
                                if (map[ny+j][nx+B-1] == -2) {
                                    check = false;
                                    break;
                                }
                            }
                        }
                        else if (i == 2) {
                            for (int j = 0; j < B; j++) {
                                if (map[ny+A-1][nx+j] == -2) {
                                    check = false;
                                    break;
                                }
                            }
                        }
                        else {
                            for (int j = 0; j < A; j++) {
                                if (map[ny+j][nx] == -2) {
                                    check = false;
                                    break;
                                }
                            }
                        }
                        if (check) {
                            map[ny][nx] = map[y][x] + 1;
                            q.add(new Pair(ny, nx));
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