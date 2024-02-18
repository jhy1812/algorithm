import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int M;
    public static int[] result;
    public static int[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        result = new int[M];
        visited = new int[N];

        dfs(0);
    }

    private static void dfs(int lv) {
        if (lv == M) {
            for (int i = 0; i < M; i++) {
                System.out.print(result[i] + " ");
            }
            System.out.println("");
            return;
        }

        for (int i = 0; i < N; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                result[lv] = i + 1;
                dfs(lv + 1);
                visited[i] = 0;
            }
        }
    }
}