import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());

        int ys = 0;
        int ms = 0;
        int[] lst = new int[N];

        for (int i = 0; i < N; i++) {
            lst[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            ys += (lst[i]/30+1)*10;
            ms += (lst[i]/60+1)*15;
        }

        if (ys > ms) System.out.print("M " + ms);
        else if (ys < ms) System.out.print("Y " + ys);
        else System.out.print("Y M " + ys);
    }
}