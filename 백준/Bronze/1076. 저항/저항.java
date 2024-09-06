import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long result = 0L;
        long[] value = new long[10];
        HashMap<String, Integer> lst = new HashMap<>();

        lst.put("black", 0);
        lst.put("brown", 1);
        lst.put("red", 2);
        lst.put("orange", 3);
        lst.put("yellow", 4);
        lst.put("green", 5);
        lst.put("blue", 6);
        lst.put("violet", 7);
        lst.put("grey", 8);
        lst.put("white", 9);

        value[0] = 1L;
        for (int i = 1; i < 10; i++) {
            value[i] = 10L * value[i-1];
        }

        String fir = br.readLine();
        String sec = br.readLine();
        String thr = br.readLine();

        result += 10L * lst.get(fir);
        result += (long) lst.get(sec);
        result *= value[lst.get(thr)];

        System.out.print(result);
    }
}