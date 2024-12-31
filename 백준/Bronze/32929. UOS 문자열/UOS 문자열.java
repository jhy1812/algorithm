import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int x = Integer.parseInt(br.readLine());

        if (x%3 == 0) System.out.print('S');
        else if (x%3 == 1) System.out.print('U');
        else System.out.print('O');
    }
}