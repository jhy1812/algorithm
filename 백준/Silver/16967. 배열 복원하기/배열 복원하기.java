import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());
        int[][] A = new int[H][W];
        int[][] B = new int[H+X][W+Y];

        for (int i = 0; i < H+X; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < W+Y; j++) B[i][j] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < X; i++) {
            for (int j = 0; j < W; j++) {
                A[i][j] = B[i][j];
                bw.write(A[i][j] + " ");
            }
            bw.write("\n");
        }

        for (int i = X; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (j < Y) A[i][j] = B[i][j];
                else A[i][j] = B[i][j] - A[i-X][j-Y];
                bw.write(A[i][j] + " ");
            }
            bw.write("\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}