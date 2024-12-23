import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        char s = br.readLine().charAt(0);
        
        if (s == 'M') System.out.print("MatKor");
        else if (s == 'W') System.out.print("WiCys");
        else if (s == 'C') System.out.print("CyKor");
        else if (s == 'A') System.out.print("AlKor");
        else System.out.print("$clear");
    }
}