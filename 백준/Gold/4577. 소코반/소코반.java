import java.io.*;
import java.util.*;

public class Main {

    public static int[] dy = {-1, 0, 1, 0};
    public static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        HashMap<Character, Integer> dir = new HashMap<>();

        dir.put('U', 0);
        dir.put('R', 1);
        dir.put('D', 2);
        dir.put('L', 3);

        int tc = 0;

        while (true) {
            tc++;
            st = new StringTokenizer(br.readLine());

            int R = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            if (R == 0 && C == 0) break;

            int y = 0;
            int x = 0;
            int ans = 0;
            int cnt = 0;
            char[][] map = new char[R][C];

            for (int i = 0; i < R; i++) {
                String tmp = br.readLine();
                for (int j = 0; j < C; j++) {
                    map[i][j] = tmp.charAt(j);
                    if (map[i][j] == 'w' || map[i][j] == 'W') {
                        y = i;
                        x = j;
                    }
                    else if (map[i][j] == 'B') {
                        ans++;
                        cnt++;
                    }
                    else if (map[i][j] == 'b') {
                        ans++;
                    }
                }
            }

            String order = br.readLine();

            for (int i = 0; i < order.length(); i++) {
                if (ans == cnt) break;
                int d = dir.get(order.charAt(i));
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (map[ny][nx] == '#') continue;
                if (map[ny][nx] == '.') map[ny][nx] = 'w';
                else if (map[ny][nx] == 'b') {
                    int nny = ny + dy[d];
                    int nnx = nx + dx[d];

                    if (map[nny][nnx] == '.') {
                        map[nny][nnx] = 'b';
                        map[ny][nx] = 'w';
                    }
                    else if (map[nny][nnx] == '+') {
                        map[nny][nnx] = 'B';
                        map[ny][nx] = 'w';
                        cnt++;
                    }
                    else continue;
                }
                else if (map[ny][nx] == 'B') {
                    int nny = ny + dy[d];
                    int nnx = nx + dx[d];

                    if (map[nny][nnx] == '.') {
                        map[nny][nnx] = 'b';
                        map[ny][nx] = 'W';
                        cnt--;
                    }
                    else if (map[nny][nnx] == '+') {
                        map[nny][nnx] = 'B';
                        map[ny][nx] = 'W';
                    }
                    else continue;
                }
                else if (map[ny][nx] == '+') {
                    map[ny][nx] = 'W';
                }

                if (map[y][x] == 'W') {
                    map[y][x] = '+';
                }
                else {
                    map[y][x] = '.';
                }
                y = ny;
                x = nx;
            }

            if (ans == cnt) bw.write("Game " + tc + ": complete\n");
            else bw.write("Game " + tc + ": incomplete\n");

            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    bw.write(map[i][j]);
                }
                bw.write("\n");
            }
        }


        br.close();
        bw.flush();
        bw.close();
    }
}