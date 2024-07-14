import java.io.*;
import java.util.*;

public class Main {

    static public int N, ret, result;
    static public int[] r;
    static public List<List<Node>> lst;
    static public int[][] board;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        r = new int[2 * N + 1];
        lst = new ArrayList<>();

        for (int i = 0; i < 2 * N + 1; i++) {
            lst.add(new ArrayList<Node>());
        }

        StringTokenizer st;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                board[i][j] = tmp;

                if (tmp == 1) {
                    lst.get(i + j).add(new Node(i, j));
                }
            }
        }

        dfs(0, 0);
        result += ret;
        ret = 0;
        dfs(1, 0);
        result += ret;

        System.out.print(result);
    }

    static private void dfs(int lv, int cnt) {
        if ((lv + 1) / 2 == N) {
            ret = Math.max(ret, cnt);
            return;
        }

        for (int i = 0; i <= lst.get(lv).size(); i++) {
            if (i == lst.get(lv).size()) {
                dfs(lv + 2, cnt);
                break;
            }

            Node node = lst.get(lv).get(i);
            int y = node.getY();
            int x = node.getX();

            if (r[y - x + N] == 0) {
                r[y - x + N] = 1;
                dfs(lv + 2, cnt + 1);
                r[y - x + N] = 0;
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