import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        long mod = 100000L;

        long[][][] lst = new long[h][w][2];

        for (int i = 0; i < h; i++) {
            lst[i][0][1] = 1;
        }

        for (int i = 0; i < w; i++) {
            lst[0][i][0] = 1;
        }

        for (int i = 1; i < h; i++) {
            for (int j = 1; j < w; j++) {
                lst[i][j][0] = (lst[i][j-1][0] + lst[i-1][j-1][1])%mod;
                lst[i][j][1] = (lst[i-1][j][1] + lst[i-1][j-1][0])%mod;
            }
        }

        System.out.print((lst[h-1][w-1][0] + lst[h-1][w-1][1])%mod);
    }
}