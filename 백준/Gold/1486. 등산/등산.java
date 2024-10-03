import java.io.*;
import java.util.*;

public class Main {
    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};

    public static int N, M, T, D, result;
    public static int[][] mt, fr, ba;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        mt = new int[N][M];
        fr = new int[N][M];
        ba = new int[N][M];

        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            Arrays.fill(fr[i], -1);
            for (int j = 0; j < M; j++) {
                if (tmp.charAt(j)-'a' >= 0) {
                    mt[i][j] = tmp.charAt(j)-'a'+26;
                }
                else {
                    mt[i][j] = tmp.charAt(j)-'A';
                }
            }
        }

        bfs1(0, 0, D);

        result = mt[0][0];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (result < mt[i][j] && fr[i][j] != -1) {
                    for (int k = 0; k < N; k++) {
                        Arrays.fill(ba[k], -1);
                    }
                    bfs2(i, j, D-fr[i][j]);

                    if (ba[0][0] != -1) result = mt[i][j];
                }
            }
        }

        System.out.print(result);
    }

    public static void bfs1(int y, int x, int lim) {
        PriorityQueue<Node> q = new PriorityQueue<>();
        q.add(new Node(y, x, 0));
        fr[y][x] = 0;

        while (!q.isEmpty()) {
            Node now = q.poll();
            int yy = now.getY();
            int xx = now.getX();
            int dd = now.getD();

            for (int i = 0; i < 4; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                    if (0 < mt[ny][nx]-mt[yy][xx] && mt[ny][nx]-mt[yy][xx] <= T) {
                        if (fr[ny][nx] == -1 || fr[ny][nx] > dd+(mt[ny][nx]-mt[yy][xx])*(mt[ny][nx]-mt[yy][xx])) {
                            if (dd+(mt[ny][nx]-mt[yy][xx])*(mt[ny][nx]-mt[yy][xx]) < lim){
                                fr[ny][nx] = dd+(mt[ny][nx]-mt[yy][xx])*(mt[ny][nx]-mt[yy][xx]);
                                q.add(new Node(ny, nx, fr[ny][nx]));
                            }
                        }
                    }
                    else if (0 <= mt[yy][xx]-mt[ny][nx] && mt[yy][xx]-mt[ny][nx] <=T) {
                        if (fr[ny][nx] == -1 || fr[ny][nx] > dd+1) {
                            if (dd+1 < lim) {
                                fr[ny][nx] = fr[yy][xx]+1;
                                q.add(new Node(ny, nx, fr[ny][nx]));
                            }
                        }
                    }
                }
            }
        }
    }

    public static void bfs2(int y, int x, int lim) {
        PriorityQueue<Node> q = new PriorityQueue<>();
        q.add(new Node(y, x, 0));
        ba[y][x] = 0;

        while(!q.isEmpty()) {
            Node now = q.poll();
            int yy = now.getY();
            int xx = now.getX();
            int dd = now.getD();
            
            if (yy == 0 && xx == 0) return;
            
            for (int i = 0; i < 4; i++) {
                int ny = yy + dy[i];
                int nx = xx + dx[i];

                if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                    if (0 < mt[ny][nx]-mt[yy][xx] && mt[ny][nx]-mt[yy][xx] <= T) {
                        if (ba[ny][nx] == -1 || ba[ny][nx] > dd+(mt[ny][nx]-mt[yy][xx])*(mt[ny][nx]-mt[yy][xx])) {
                            if (dd+(mt[ny][nx]-mt[yy][xx])*(mt[ny][nx]-mt[yy][xx]) <= lim){
                                ba[ny][nx] = dd+(mt[ny][nx]-mt[yy][xx])*(mt[ny][nx]-mt[yy][xx]);
                                q.add(new Node(ny, nx, ba[ny][nx]));
                            }
                        }
                    }
                    else if (0 <= mt[yy][xx]-mt[ny][nx] && mt[yy][xx]-mt[ny][nx] <=T) {
                        if (ba[ny][nx] == -1 || ba[ny][nx] > dd+1) {
                            if (dd+1 <= lim) {
                                ba[ny][nx] = dd+1;
                                q.add(new Node(ny, nx, ba[ny][nx]));
                            }
                        }
                    }
                }
            }
        }
    }
}

class Node implements Comparable<Node> {
    private int y;
    private int x;
    private int d;

    public Node(int y, int x, int d) {
        this.y = y;
        this.x = x;
        this.d = d;
    }

    public int getY() {
        return this.y;
    }

    public int getX() {
        return this.x;
    }

    public int getD() {
        return this.d;
    }

    @Override
    public int compareTo(Node n) {
        if (this.d > n.getD()) return 1;
        return -1;
    }
}