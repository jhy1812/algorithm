import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int[] dy = {0, 0, 1};
    public static int[] dx = {1, -1, 0};
    public static int[][] visited;
    public static String[] map;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        dx[2] = Integer.parseInt(st.nextToken());

        map = new String[2];

        map[0] = br.readLine();
        map[1] = br.readLine();

        visited = new int[2][N];

        Arrays.fill(visited[0], -1);
        Arrays.fill(visited[1], -1);

        if (bfs()) System.out.print(1);
        else System.out.print(0);
    }

    public static boolean bfs() {
        Queue<Integer> q = new LinkedList<>();
        visited[0][0] = 0;
        q.add(0);

        while (!q.isEmpty()) {
            int now = q.poll();
            int y = now/N;
            int x = now%N;

            for (int i = 0; i < 3; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (nx >= N) return true;

                ny %= 2;

                if (visited[y][x] >= nx || nx < 0) continue;
                if (map[ny].charAt(nx) == '0' || visited[ny][nx] != -1) continue;

                visited[ny][nx] = visited[y][x] + 1;
                q.add(ny*N+nx);
            }
        }

        return false;
    }
}

