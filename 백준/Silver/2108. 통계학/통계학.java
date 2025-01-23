import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] lst = new int[8001];
        int max = -4001;
        int min = 4001;
        int sum = 0;
        int cnt = 0;
        int mode = 0;
        int median = 0;

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(br.readLine());
            max = Math.max(max, tmp);
            min = Math.min(min, tmp);
            sum += tmp;
            tmp += 4000;
            lst[tmp]++;
            cnt = Math.max(cnt, lst[tmp]);
        }

        sum = (int) Math.round((double) sum/N);

        int check = 0;
        int count = 0;
        boolean flag = false;

        for (int i = 0; i <= 8000; i++) {
            if (lst[i] == cnt && check < 2) {
                check++;
                mode = i;
            }
            count += lst[i];
            if (count > N/2 && !flag) {
                flag = true;
                median = i;
            }
        }

        mode -= 4000;
        median -= 4000;

        bw.write(sum + "\n");
        bw.write(median + "\n");
        bw.write(mode + "\n");
        bw.write((max-min) + "\n");

        br.close();
        bw.flush();
        bw.close();
    }
}