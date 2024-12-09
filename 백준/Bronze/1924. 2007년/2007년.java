import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int month = Integer.parseInt(st.nextToken());
        int day = Integer.parseInt(st.nextToken());

        int[] months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String[] results = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

        int ret = 0;

        for (int i = 0; i < month-1; i++) ret += months[i];
        ret += day-1;

        System.out.print(results[ret%7]);
    }
}