import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int num = 0;
        int score = 0;

        for (int i = 1; i <= 5; i++) {
            st = new StringTokenizer(br.readLine());
            int tmp = 0;
            for (int j = 0; j < 4; j++) {
                tmp += Integer.parseInt(st.nextToken());
            }

            if (tmp > score) {
                num = i;
                score = tmp;
            }
        }

        System.out.print(num + " " + score);
    }
}