import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());
        int[] arr = new int[N];
        int result = 0;
        StringTokenizer st = new StringTokenizer(bf.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            arr[i] = tmp;
        }
        
        Arrays.sort(arr);
        
        for (int i = 0; i < N / 2; i++) {
            result += 2 * arr[N - i - 1];
        }

        if (N % 2 == 1) {
            result += arr[N / 2];
        }

        System.out.print(result);
    }
}