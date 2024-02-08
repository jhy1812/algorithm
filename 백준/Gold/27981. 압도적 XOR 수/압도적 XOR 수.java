import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        int K = sc.nextInt();

        long mul = 2;
        long lef = 1;
        long rig;

        while(K > 0) {
            if (K % 2 == 1) {
                lef *= mul;
            }
            K /= 2;
            mul *= mul;
        }
        rig = lef - 1;
        long std = 2;
        long result = 0;
        while(true) {
            if (std > N) {
                long l = N - std + (std - 1) / lef + 2;
                if (l > 0) {
                    result += l;
                }
                break;
            }
            else {
                long l = 1 + (std - 1) / lef;
                if ( l > 0) {
                    result += l;
                }
                std *= 2;
            }
        }

        System.out.print(result);
    }
}