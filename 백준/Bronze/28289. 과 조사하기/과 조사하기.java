import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int P = Integer.parseInt(br.readLine());

        int so = 0;
        int im = 0;
        int ai = 0;
        int no = 0;

        for (int i = 0; i < P; i++) {
            st = new StringTokenizer(br.readLine());
            int g = Integer.parseInt(st.nextToken());
            if (g == 1) {
                no++;
            }
            else {
                int c = Integer.parseInt(st.nextToken());
                if (c == 1 || c == 2) {
                    so++;
                }
                else if (c == 3) {
                    im++;
                }
                else {
                    ai++;
                }
            }
        }

        System.out.println(so);
        System.out.println(im);
        System.out.println(ai);
        System.out.print(no);
    }
}