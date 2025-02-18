import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int[] lst = new int[N];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            lst[i] = Integer.parseInt(st.nextToken())%K;
        }

        Arrays.sort(lst);

        st = new StringTokenizer(br.readLine());
        int a = 0;

        for (int i = 0; i < T; i++) {
            a += Integer.parseInt(st.nextToken());
            a %= K;
            int s = 0;
            int e = N-1;
            int tar = K-a-1;

            while (s <= e) {
                int mid = (s + e)/2;

                if (lst[mid] < tar) {
                    s = mid+1;
                }
                else if (lst[mid] > tar) {
                    e = mid-1;
                }
                else {
                    s = mid+1;
                    break;
                }

            }
            if (s == 0) {
                bw.write((lst[N-1]+a)%K + " ");
            }
            else {
                bw.write((lst[s-1]+a)%K + " ");
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}