import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, S, D;
    public static int[] result;
    public static int[][] node;
    public static List<List<List<Path>>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            if (N == 0 && M == 0) {
                break;
            }

            result = new int[N];
            node = new int[N][2];
            arr = new ArrayList<>();
            arr.add(new ArrayList<>());
            arr.add(new ArrayList<>());

            Arrays.fill(result, -1);

            for (int i = 0; i < N; i++) {
                node[i][0] = -1;
                node[i][1] = -1;
                arr.get(0).add(new ArrayList<>());
                arr.get(1).add(new ArrayList<>());
            }

            st = new StringTokenizer(br.readLine());
            S = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int U = Integer.parseInt(st.nextToken());
                int V = Integer.parseInt(st.nextToken());
                int P = Integer.parseInt(st.nextToken());
                arr.get(0).get(U).add(new Path(V, P));
                arr.get(1).get(V).add(new Path(U, P));
            }

            bfs(S, 0);
            bfs(D, 1);
            solve(S);

            bw.write(result[D] + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void bfs(int s, int state) {
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        node[s][state] = 0;

        while(!q.isEmpty()) {
            int no = q.poll();
            for (Path p : arr.get(state).get(no)) {
                int ne = p.getV();
                int di = p.getD();

                if (node[ne][state] == -1) {
                    node[ne][state] = node[no][state] + di;
                    q.add(ne);
                }
                else {
                    if (node[ne][state] > node[no][state] + di) {
                        node[ne][state] = node[no][state] + di;
                        q.add(ne);
                    }
                }
            }
        }
    }

    public static void solve(int s) {
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        result[s] = 0;
        while(!q.isEmpty()) {
            int no = q.poll();

            for (Path p : arr.get(0).get(no)) {
                int ne = p.getV();
                int d = p.getD();
                if (node[ne][1] == -1) continue;
                if (node[no][0] + d + node[ne][1] != node[D][0]) {
                    if (result[ne] == -1 || result[ne] > result[no] + d) {
                        result[ne] = result[no] + d;
                        q.add(ne);
                    }
                }
            }
        }
    }
}

class Path implements Comparable<Path> {
    private int v;
    private int d;

    public Path(int v, int d) {
        this.v = v;
        this.d = d;
    }

    public int getV() {
        return this.v;
    }

    public int getD() {
        return this.d;
    }

    @Override
    public int compareTo(Path P) {
        if (this.d > P.d) {
            return 1;
        }
        return -1;
    }
}