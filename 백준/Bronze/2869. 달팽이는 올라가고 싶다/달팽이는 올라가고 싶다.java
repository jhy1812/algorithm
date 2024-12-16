import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int V = Integer.parseInt(st.nextToken());

        int day = V/(A-B) + 1;
        int result = day;

        while (true) {
            day--;
            if ((A-B)*day+A >= V) result = day+1;
            else break;
        }

        System.out.print(result);
    }
}