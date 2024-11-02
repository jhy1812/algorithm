import java.io.*;
import java.util.*;

public class Main {

    public static int[] arr;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int G = Integer.parseInt(br.readLine());
        int P = Integer.parseInt(br.readLine());
        int result = 0;

        arr = new int[G+1];

        Arrays.fill(arr, -1);
        for (int i = 0; i < P; i++) {
            int g = Integer.parseInt(br.readLine());
            int fg = findBoss(g);

            if (fg == 0) break;

            union(fg-1, fg);
            result++;
        }

        System.out.print(result);
    }

    public static int findBoss(int a) {
        if (arr[a] == -1) return a;

        int ret = findBoss(arr[a]);
        arr[a] = ret;

        return ret;
    }

    public static void union(int a, int b) {
        int fa = findBoss(a);
        int fb = findBoss(b);

        if (fa == fb) return;

        arr[fb] = fa;
    }
}