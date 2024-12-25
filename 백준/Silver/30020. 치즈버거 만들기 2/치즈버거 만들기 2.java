import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        if (A <= B || A-B > B) bw.write("NO");
        else {
            bw.write("YES\n");
            bw.write((A-B) + "\n");

            while (true) {
                if (A == B+1) {
                    for (int i = 0; i < B; i++) {
                        bw.write("ab");
                    }
                    bw.write("a");
                    break;
                }
                bw.write("aba\n");
                A -= 2;
                B--;
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}