import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        A--;
        int n = 0;
        int result = 0;
        while (true) {
            if (n*(n+1)/2 > A) {
                n--;
                A -= n*(n+1)/2;
                break;
            }
            else if (n*(n+1)/2 == A) {
                A -= n*(n+1)/2;
                break;
            }
            n++;
        }

        result -= n*(n+1)*(2*n+1)/6;
        result -= A*(++n);

        n = 0;

        while (true) {
            if (n*(n+1)/2 > B) {
                n--;
                B -= n*(n+1)/2;
                break;
            }
            else if (n*(n+1)/2 == B) {
                B -= n*(n+1)/2;
                break;
            }
            n++;
        }
        result += n*(n+1)*(2*n+1)/6;
        result += B*(++n);

        System.out.print(result);
    }
}