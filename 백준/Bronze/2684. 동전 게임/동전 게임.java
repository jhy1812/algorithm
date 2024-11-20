import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int P = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= P; tc++) {
            String S = br.readLine();

            int[] result = new int[8];

            for (int i = 0; i < 38; i++) {
                if (S.startsWith("TTT", i)) result[0]++;
                else if (S.startsWith("TTH", i)) result[1]++;
                else if (S.startsWith("THT", i)) result[2]++;
                else if (S.startsWith("THH", i)) result[3]++;
                else if (S.startsWith("HTT", i)) result[4]++;
                else if (S.startsWith("HTH", i)) result[5]++;
                else if (S.startsWith("HHT", i)) result[6]++;
                else result[7]++;
            }

            for (int i = 0; i < 8; i++) {
                bw.write(result[i] + " ");
            }
            bw.write("\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}