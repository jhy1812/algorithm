import java.io.*;
import java.util.*;

public class Main {
    public static int N, M, r;
    public static int MIN = -1000000000;
    public static long sum;
    public static int[] boss, lev;
    public static boolean[] check;
    public static int[][] par, dis;
    public static List<List<Node>> arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        r = Integer.MAX_VALUE;
        lev = new int[N+1];
        boss = new int[N+1];
        check = new boolean[M];
        dis = new int[N+1][20];
        par = new int[N+1][20];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
            Arrays.fill(dis[i], MIN);
        }

        Queue<Path> q = new LinkedList<>();
        PriorityQueue<Path> pq = new PriorityQueue<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            pq.add(new Path(u, v, w, i));
            q.add(new Path(u, v, w, i));
        }

        int cnt = 0;

        for (int i = 0; i < M; i++) {
            Path p = pq.poll();
            assert p != null;
            int u = p.getU();
            int v = p.getV();
            int w = p.getW();
            int n = p.getN();
            if (union(u, v)) {
                arr.get(u).add(new Node(v, w));
                arr.get(v).add(new Node(u, w));
                check[n] = true;
                sum += (long) w;
                r = Math.min(r, u);
                cnt++;
            }
            if (cnt == N - 1) {
                pq.clear();
                break;
            }
        }
        dfs(1, r, 0, MIN);
        for (int i = 0; i < M; i++) {
            Path p = q.poll();
            assert p != null;
            int n = p.getN();

            if (check[n]) {
                bw.write(sum + "\n");
            }
            else {
                int u = p.getU();
                int v = p.getV();
                int w = p.getW();
                int d = LCA(u, v);
                long result = (long) sum - d + w;
                bw.write(result + "\n");
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void dfs(int lv, int cur, int parent, int d) {
        lev[cur] = lv;
        par[cur][0] = parent;
        dis[cur][0] = d;

        for (int i = 1; i < 20; i++) {
            par[cur][i] = par[par[cur][i-1]][i-1];
            dis[cur][i] = Math.max(dis[cur][i-1], dis[par[cur][i-1]][i-1]);
        }

        for (Node node : arr.get(cur)) {
            int child = node.getV();
            if (child == parent) continue;
            dfs(lv + 1, child, cur, node.getW());
        }
    }

    public static int LCA(int a, int b) {
        int ret = MIN;

        if (lev[a] < lev[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        if (lev[a] != lev[b]) {
            for (int i = 19; i >= 0; i--) {
                if (lev[par[a][i]] >= lev[b]) {
                    ret = Math.max(ret, dis[a][i]);
                    a = par[a][i];
                }
            }
        }

        if (a != b) {
            for (int i = 19; i >= 0; i--) {
                if (par[a][i] != par[b][i]) {
                    ret = Math.max(ret, dis[a][i]);
                    ret = Math.max(ret, dis[b][i]);
                    a = par[a][i];
                    b = par[b][i];
                }
            }
        }

        if (a != b) {
            ret = Math.max(ret, dis[a][0]);
            ret = Math.max(ret, dis[b][0]);
        }

        return ret;
    }

    public static int findBoss(int a) {
        if (boss[a] == 0) {
            return a;
        }

        int ret = findBoss(boss[a]);
        boss[a] = ret;
        return ret;
    }

    public static boolean union(int a, int b) {
        int fa = findBoss(a);
        int fb = findBoss(b);

        if (fa == fb) {
            return false;
        }

        boss[fb] = fa;
        return true;
    }
}

class Node {
    private int v;
    private int w;

    public Node(int v, int w) {
        this.v = v;
        this.w = w;
    }

    public int getV() {
        return this.v;
    }

    public int getW() {
        return this.w;
    }
}
class Path implements Comparable<Path> {
    private int u;
    private int v;
    private int w;
    private int n;

    public Path(int u, int v, int w, int n) {
        this.u = u;
        this.v = v;
        this.w = w;
        this.n = n;
    }

    public int getU() {
        return this.u;
    }

    public int getV() {
        return this.v;
    }

    public int getW() {
        return this.w;
    }

    public int getN() {
        return this.n;
    }

    @Override
    public int compareTo(Path p) {
        if (this.w > p.w) {
            return 1;
        }

        return -1;
    }
}