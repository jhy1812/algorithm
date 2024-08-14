import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        boolean flag = true;
        int[] cr = new int[N];
        int[] sh = new int[N];

        Queue<Integer> re = new LinkedList<>();
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            cr[i] = tmp;
        }

        Arrays.sort(cr);

        int M = Integer.parseInt(br.readLine());
        int min = M / N;

        if (M%N != 0) {
            min++;
        }

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < M; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            q.add(tmp);
        }


        while (!q.isEmpty()) {
            for (int i = N-1; i >= 0; i--) {
                int load = 0;
                while(!q.isEmpty() && load < min) {
                    int tmp = q.poll();
                    if (cr[i] >= tmp) {
                        sh[i]++;
                        load++;
                    }
                    else {
                        re.add(tmp);
                    }
                }
            }
        }

        while(!re.isEmpty() && flag) {
            for (int i = N-1; i >= 0; i--) {
                if (re.isEmpty()) {
                    break;
                }
                int tmp = re.peek();
                if (i == N-1 && cr[i] < tmp) {
                    flag = false;
                    break;
                }
                else if (cr[i] >= tmp) {
                    re.poll();
                    sh[i]++;
                    if (i != N-1) {
                        while (sh[i] < sh[i+1] && !re.isEmpty()) {
                            re.poll();
                            sh[i]++;
                        }
                    }
                }
                else if (cr[i] < tmp) {
                    break;
                }
            }
        }

        if (flag) {
            for (int i = 0; i < N; i++) {
                result = Math.max(result, sh[i]);
            }
            System.out.print(result);
        }
        else {
            System.out.print(-1);
        }
    }
}