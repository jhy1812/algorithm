import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        String space = "";
        String sign = "";
        for (int i = 0; i < N; i++) {
            space += " ";
            sign += "@";
        }

        String st = "@";
        String ed = "@\n";
        sign = st + sign + ed;
        space = st + space + ed;

        sb.append(sign);

        for (int i = 0; i < N; i++) {
            sb.append(space);
        }

        sb.append(sign);

        System.out.print(sb.toString());
    }
}