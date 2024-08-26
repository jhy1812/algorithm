import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String result = "";
        
        for (int i = 0; i < 15; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 15; j++) {
                char tmp = st.nextToken().charAt(0);
                if (tmp == 'w') {
                    result = "chunbae";            
                }
                else if (tmp == 'b') {
                    result = "nabi";
                }
                else if (tmp == 'g') {
                    result = "yeongcheol";
                }
            }
        }
        
        System.out.print(result);
    }
}