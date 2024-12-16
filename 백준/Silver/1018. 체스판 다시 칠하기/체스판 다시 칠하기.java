import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int result = N*M;
        String[] board = new String[N];

        for (int i = 0; i < N; i++) {
            board[i] = br.readLine();
        }

        for (int i = 0; i < N-7; i++) {
            for (int j = 0; j < M-7; j++) {
                int tmp = 0;
                for (int k = 0; k < 8; k++) {
                    for (int m = 0; m < 8; m++) {
                        if ((k+m)%2 == 0) {
                            if (board[i+k].charAt(j+m) == 'B') tmp++;
                        }
                        else {
                            if (board[i+k].charAt(j+m) == 'W') tmp++;
                        }
                    }
                }
                result = Math.min(result, tmp);
                result = Math.min(result, 64-tmp);
            }
        }

        System.out.print(result);
    }
}