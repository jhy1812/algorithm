import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int result = 0;
        int[] cp = new int[7];

        for (int i = 1; i <= 6; i++) {
            cp[i] = Integer.parseInt(br.readLine());
        }

        result += cp[6] + cp[5];

        cp[1] = Math.max(0, cp[1] - 11*cp[5]);

        result += cp[4];

        if (5*cp[4] <= cp[2]) {
            cp[2] -= 5*cp[4];
        }
        else {
            cp[1] = Math.max(0, cp[1] - 4*(5*cp[4] - cp[2]));
            cp[2] = 0;
        }

        result += cp[3]/4;
        result += cp[3]%4 == 0 ? 0 : 1;

        if (cp[3]%4 == 1) {
            if (5 <= cp[2]) {
                cp[2] -= 5;
                cp[1] = Math.max(0, cp[1] - 7);
            }
            else {
                cp[1] = Math.max(0, cp[1] - (27 - 5*cp[2]));
                cp[2] = 0;
            }
        }
        else if (cp[3]%4 == 2) {
            if (3 <= cp[2]) {
                cp[2] -= 3;
                cp[1] = Math.max(0, cp[1] - 6);
            }
            else {
                cp[1] = Math.max(0, cp[1] - (18 - 4*cp[2]));
                cp[2] = 0;
            }
        }
        else if (cp[3]%4 == 3) {
            if (1 <= cp[2]) {
                cp[2] -= 1;
                cp[1] = Math.max(0, cp[1] - 5);
            }
            else {
                cp[1] = Math.max(0, cp[1] - (9 - 4*cp[2]));
                cp[2] = 0;
            }
        }

        result += cp[2]/9;
        result += cp[2]%9 == 0 ? 0 : 1;

        if (cp[2]%9 > 0) {
            cp[1] = Math.max(0, cp[1] - (36 - 4*(cp[2]%9)));
        }

        result += cp[1]/36;
        result += cp[1]%36 == 0 ? 0 : 1;

        System.out.print(result);
    }
}