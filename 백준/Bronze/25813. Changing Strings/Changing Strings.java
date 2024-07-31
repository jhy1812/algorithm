import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        StringBuilder ret = new StringBuilder();
        int sw = 0;
        int e = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == 'F') {
                e = i;
                break;
            }
        }
        
        
        for (int i = 0; i < s.length(); i++) {
            if (sw == 0 && s.charAt(i) == 'U') {
                sw++;
                ret.append("U");
            }
            else if (i == e) {
                sw++;
                ret.append("F");
            }
            else if (sw == 0) {
                ret.append("-");
            }
            else if (sw == 1) {
                ret.append("C");
            }
            else {
                ret.append("-");
            }
        }

        System.out.print(ret);
    }
}