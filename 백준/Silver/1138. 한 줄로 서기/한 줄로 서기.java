import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        int[] result = new int[N];
        Arrays.fill(result, -1);

        for (int i = 0 ; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            arr[i] = tmp;
        }

        for (int i = 0; i < N; i++) {
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (cnt == arr[i] && result[j] == -1) {
                    result[j] = i + 1;
                    break;
                }
                if (result[j] == -1 && cnt < arr[i]) {
                    cnt++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            System.out.print(result[i] + " ");
        }
    }
}