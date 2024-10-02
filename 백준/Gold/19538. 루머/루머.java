import java.io.*;
import java.util.*;

public class Main {

    public static int N, M;
    public static int[] nb, check, result;
    public static List<List<Integer>> arr;
    public static Queue<Integer> q;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        nb = new int[N+1];
        check = new int[N+1];
        result = new int[N+1];
        arr = new ArrayList<>();
        q = new LinkedList<>();

        Arrays.fill(result, -1);

        for (int i = 0; i <= N; i++) arr.add(new ArrayList<>());

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int tmp = Integer.parseInt(st.nextToken());
            while (tmp != 0) {
                arr.get(i).add(tmp);
                tmp = Integer.parseInt(st.nextToken());
            }
            check[i] = arr.get(i).size()/2 + arr.get(i).size()%2;
        }

        M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < M; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            result[tmp] = 0;
            q.add(tmp);
        }

        bfs();

        for (int i = 1; i <= N; i++) {
            bw.write(result[i] + " ");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void bfs() {
        while (!q.isEmpty()) {
            int now = q.poll();

            for (int n : arr.get(now)) {
                nb[n]++;
                if (nb[n] >= check[n] && result[n] == -1) {
                    result[n] = result[now] + 1;
                    q.add(n);
                }
            }
        }
    }
}