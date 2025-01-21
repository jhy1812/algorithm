import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> q = new PriorityQueue<>();

        int cut = (int) Math.round(0.15*n);

        for (int i = 0; i < n; i++) {
            q.add(Integer.parseInt(br.readLine()));
        }

        for (int i = 0; i < cut; i++) q.poll();

        int sum = 0;

        for (int i = 0; i < n-2*cut; i++) sum += q.poll();

        int result = (int) Math.round((double) sum/(n-2*cut));

        System.out.print(result);
    }
}