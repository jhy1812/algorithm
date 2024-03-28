import java.io.*;
import java.util.*;
public class Main {
    public static int N, M, check, result;
    public static int[] visited;
    public static List<List<Integer>> arr;
    public static List<List<Integer>> lst;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new ArrayList<>();
        lst = new ArrayList<>();
        for (int i = 0 ; i <= N; i++) {
            arr.add(new ArrayList<Integer>());
            lst.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr.get(a).add(b);
            lst.get(b).add(a);
        }

        for (int i = 1; i <= N; i++) {
            check = 0;
            visited = new int[N + 1];
            visited[i] = 1;
            sol1(i);
            sol2(i);
            if (check == N - 1) {
                result++;
            }
        }

        System.out.print(result);
    }

    private static void sol1(int st) {
        for (int i = 0; i < arr.get(st).size(); i++) {
            int now = arr.get(st).get(i);
            if (visited[now] == 0) {
                visited[now] = 1;
                sol1(now);
                check++;
            }
        }
    }

    private static void sol2(int st) {
        for (int i = 0; i < lst.get(st).size(); i++) {
            int now = lst.get(st).get(i);
            if (visited[now] == 0) {
                visited[now] = 1;
                sol2(now);
                check++;
            }
        }
    }
}