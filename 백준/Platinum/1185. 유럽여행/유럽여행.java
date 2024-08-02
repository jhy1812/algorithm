import java.io.*;
import java.util.*;

public class Main {

    private static int[] cost, boss;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        int result = Integer.MAX_VALUE;
        cost = new int[N + 1];
        boss = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            int tmp = Integer.parseInt(br.readLine());
            result = Math.min(result, tmp);
            cost[i] = tmp;
        }

        PriorityQueue<Path> q = new PriorityQueue<>();

        for (int i = 0; i < P; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            q.add(new Path(u, v, cost[u] + cost[v] + 2*c));
        }

        int cnt = 0;

        for (int i = 0; i < P; i++) {
            Path p = q.poll();
            int u = p.getU();
            int v = p.getV();
            int c = p.getCost();

            if (!union(u, v)) {
                cnt++;
                result += c;
            }
            if (cnt == N - 1) {
                break;
            }
        }

        System.out.print(result);
    }

    private static int findBoss(int a) {
        if (boss[a] == 0) {
            return a;
        }
        int ret = findBoss(boss[a]);
        boss[a] = ret;
        return ret;
    }

    private static boolean union(int a, int b) {
        int fa = findBoss(a);
        int fb = findBoss(b);
        if (fa == fb) {
            return true;
        }
        boss[fb] = fa;
        return false;
    }
}

class Path implements Comparable<Path> {
    private int u;
    private int v;
    private int cost;

    public Path(int u, int v, int cost) {
        this.u = u;
        this.v = v;
        this.cost = cost;
    }

    public int getU() {
        return this.u;
    }

    public int getV() {
        return this.v;
    }

    public int getCost() {
        return this.cost;
    }

    @Override
    public int compareTo(Path p) {
        if (this.cost > p.cost) {
            return 1;
        }
        return -1;
    }
}