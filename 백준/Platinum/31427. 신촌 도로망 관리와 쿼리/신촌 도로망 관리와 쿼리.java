import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, Q, cnt;
    public static String s = "00000";
    public static int[] boss, visited, seq;
    public static List<List<Path>> arr;
    public static int[][] result;
    public static HashMap<String, Integer> com;
    public static HashMap<Character, Integer> uni;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        uni = new HashMap<>();
        uni.put('A', 0);
        uni.put('B', 1);
        uni.put('C', 2);
        uni.put('D', 3);
        uni.put('E', 4);

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        cnt = 0;
        visited = new int[5];
        seq = new int[5];
        boss = new int[N + 1];
        result = new int[120][5];
        arr = new ArrayList<>();
        com = new HashMap<>();

        for (int i = 0; i < 5; i++) {
            arr.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            char c = st.nextToken().charAt(0);
            arr.get(uni.get(c)).add(new Path(u, v));
        }

        dfs(0);

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            PriorityQueue<Path> q = new PriorityQueue<>();
            int[] cost = new int[5];
            long ret = 0;
            StringBuilder ns = new StringBuilder();
            for (int j = 0; j < 5; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                q.add(new Path(j, tmp));
            }
            for (int j = 0; j < 5; j++) {
                Path p = q.poll();
                ns.append(p.getU());
                cost[j] = p.getV();
            }
            int now = com.get(ns.toString());
            for (int j = 0; j < 5; j++) {
                ret += (long) result[now][j] * cost[j];
            }

            bw.write(Long.toString(ret) + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    private static void dfs(int lv) {
        if (lv == 5) {
            com.put(s, cnt);
            int count = 0;
            Arrays.fill(boss, 0);
            for (int i = 0; i < 5; i++) {
                int tmp = 0;
                for (Path p : arr.get(seq[i])) {
                    int u = p.getU();
                    int v = p.getV();
                    if (union(u, v)) {
                        count++;
                        tmp++;
                    }
                    if (count == N - 1) {
                        break;
                    }
                }
                result[cnt][i] = tmp;
                if (count == N - 1) {
                    break;
                }
            }
            cnt++;
            return;
        }

        for (int i = 0; i < 5; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                seq[lv] = i;
                s = s.substring(0, lv) + i;
                dfs(lv + 1);
                visited[i] = 0;
            }
        }
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
            return false;
        }

        boss[fb] = fa;
        return true;
    }
}

class Path implements Comparable<Path> {
    private int u;
    private int v;

    public Path(int u, int v) {
        this.u = u;
        this.v = v;
    }

    public int getU() {
        return this.u;
    }

    public int getV() {
        return this.v;
    }

    @Override
    public int compareTo(Path p) {
        if (this.v > p.v) {
            return 1;
        }
        return -1;
    }
}