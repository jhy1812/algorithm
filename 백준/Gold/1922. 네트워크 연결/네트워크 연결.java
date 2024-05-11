import java.io.*;
import java.util.*;

public class Main {

    public static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());
        int M = Integer.parseInt(bf.readLine());
        int cnt = 0;
        int result = 0;
        arr = new int[N + 1];
        List<Edge> edges = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            StringTokenizer s = new StringTokenizer(bf.readLine());
            int st = Integer.parseInt(s.nextToken());
            int ed = Integer.parseInt(s.nextToken());
            int w = Integer.parseInt(s.nextToken());
            edges.add(new Edge(st, ed, w));
        }

        Collections.sort(edges);

        for (int i = 0; i < M; i++) {
            Edge e = edges.get(i);
            if (fb(e.getSt()) != fb(e.getEd())) {
                union(e.getSt(), e.getEd());
                cnt++;
                result += e.getW();
            }
            if (cnt == N - 1) {
                break;
            }
        }

        System.out.print(result);
    }

    private static int fb(int a) {
        if (arr[a] == 0) {
            return a;
        }
        int ret = fb(arr[a]);
        arr[a] = ret;
        return ret;
    }
    private static void union(int a, int b) {
        int fa = fb(a);
        int fb = fb(b);
        arr[fb] = fa;
    }
}

class Edge implements Comparable<Edge> {
    private int st;
    private int ed;
    private int w;

    public Edge(int st, int ed, int w) {
        this.st = st;
        this.ed = ed;
        this.w = w;
    }

    public int getSt() {
        return this.st;
    }

    public int getEd() {
        return this.ed;
    }

    public int getW() {
        return this.w;
    }

    @Override
    public int compareTo(Edge e) {
        return this.w - e.w;
    }
}