import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String N = br.readLine();

        if (N.charAt(0) == '0') bw.write("0");
        else if (N.charAt(0) == '1') bw.write("1");
        else if (N.charAt(0) == '2') bw.write("10");
        else if (N.charAt(0) == '3') bw.write("11");
        else if (N.charAt(0) == '4') bw.write("100");
        else if (N.charAt(0) == '5') bw.write("101");
        else if (N.charAt(0) == '6') bw.write("110");
        else if (N.charAt(0) == '7') bw.write("111");

        for (int i = 1; i < N.length(); i++) {
            if (N.charAt(i) == '0') bw.write("000");
            else if (N.charAt(i) == '1') bw.write("001");
            else if (N.charAt(i) == '2') bw.write("010");
            else if (N.charAt(i) == '3') bw.write("011");
            else if (N.charAt(i) == '4') bw.write("100");
            else if (N.charAt(i) == '5') bw.write("101");
            else if (N.charAt(i) == '6') bw.write("110");
            else if (N.charAt(i) == '7') bw.write("111");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}