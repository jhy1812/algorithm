import java.io.*;
import java.util.*;

public class Main {

    public static int N, M;
    public static List<List<Pair>> arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int result = 0;
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            arr.get(A).add(new Pair(B, C));
            arr.get(B).add(new Pair(A, C));
        }

        st = new StringTokenizer(br.readLine());

        int S = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        int s = 1;
        int e = 1000000000;
        int mid = 0;
        while (s <= e) {
            mid = (s + e) / 2;
            if (bfs(S, T, mid)) {
                result = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        System.out.print(result);
    }

    public static boolean bfs(int start, int end, int lim) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        boolean[] visited = new boolean[N+1];
        visited[start] = true;

        while (!q.isEmpty()) {
            int now = q.poll();
            
            for (Pair p : arr.get(now)) {
                int next = p.getV();
                int dis = p.getD();
                
                if (dis >= lim && !visited[next]) {
                    if (next == end) return true;
                    visited[next] = true;
                    q.add(next);
                }
            }
        }
        
        return false;
    }
}

class Pair {
    private int v;
    private int d;

    public Pair(int v, int d) {
        this.v = v;
        this.d = d;
    }

    public int getV() {
        return this.v;
    }

    public int getD() {
        return this.d;
    }
}