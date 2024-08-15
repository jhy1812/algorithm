import java.io.*;
import java.util.*;

public class Main {

    public static int[] boss, part;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        boss = new int[1000001];
        part = new int[1000001];
        Arrays.fill(part, 1);

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            Character order = st.nextToken().charAt(0);
            int a = Integer.parseInt(st.nextToken());

            if (order == 'I') {
                int b = Integer.parseInt(st.nextToken());
                union(a, b);
            }
            else {
                bw.write(part[findBoss(a)] + "\n");
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static int findBoss(int a) {
        if (boss[a] == 0) {
            return a;
        }

        int ret = findBoss(boss[a]);
        boss[a] = ret;
        return ret;
    }

    public static boolean union(int a, int b) {
        int fa = findBoss(a);
        int fb = findBoss(b);

        if (fa == fb) {
            return true;
        }
        if (fa > fb) {
            int tmp = fa;
            fa = fb;
            fb = tmp;
        }

        boss[fb] = fa;
        part[fa] += part[fb];

        return false;
    }
}