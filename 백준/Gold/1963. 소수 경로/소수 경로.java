import java.io.*;
import java.util.*;

public class Main {

    public static int A, B;
    public static int[] visited;
    public static boolean[] prime;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        prime = new boolean[10001];

        Arrays.fill(prime, true);

        for (int i = 2; i <= 5000; i++) {
            if (prime[i]) {
                for (int j = 2*i; j <= 10000; j+=i) {
                    prime[j] = false;
                }
            }
        }

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            visited = new int[10001];
            Arrays.fill(visited, -1);

            bw.write(bfs(A) + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static String bfs(int s) {
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        visited[s] = 0;

        while (!q.isEmpty()) {
            int now = q.poll();

            if (now == B) return String.valueOf(visited[now]);
            int a = 10;
            int b = 1;
            for (int i = 0; i < 4; i++) {
                int tmp = now - (now%a - now%b);
                for (int j = 0; j < 10; j++) {
                    if (i == 3 && j == 0) continue;
                    int num = tmp + j*b;

                    if (visited[num] == -1 && prime[num]) {
                        visited[num] = visited[now]+1;
                        q.add(num);
                    }
                }

                a *= 10;
                b *= 10;
            }
        }

        return "Impossible";
    }
}