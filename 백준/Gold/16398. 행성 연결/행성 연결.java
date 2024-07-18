import java.io.*;
import java.util.*;

public class Main {

    static private int N, cnt;
    static private long result;
    static private int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        result = 0;
        arr = new int[N];
        Arrays.fill(arr, -1);
        PriorityQueue<Planet> q = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < N; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                if (j <= i) {
                    continue;
                }
                q.add(new Planet(i, j, tmp));
            }
        }

        for (int i = 0; i < N * (N - 1) / 2; i++) {
            Planet p = q.poll();
            int x = p.getX();
            int y = p.getY();
            if (x > y) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            if (!union(x ,y)) {
                result += p.getCost();
                cnt++;
            }
            if (cnt == N - 1) {
                break;
            }
        }

        System.out.print(result);
    }

    static private int findBoss(int a) {
        if (arr[a] == -1) {
            return a;
        }
        return arr[a] = findBoss(arr[a]);
    }

    static private boolean union(int a, int b) {
        int fa = findBoss(a);
        int fb = findBoss(b);

        if (fa == fb) {
            return true;
        }
        arr[fb] = fa;
        return false;
    }
}

class Planet implements Comparable<Planet> {
    private int x;
    private int y;
    private int cost;

    public Planet(int x, int y, int cost) {
        this.x = x;
        this.y = y;
        this.cost = cost;
    }

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }

    public int getCost() {
        return this.cost;
    }

    @Override
    public int compareTo(Planet a) {
        return this.cost > a.cost ? 1 : -1;
    }
}