import java.io.*;
import java.util.*;

public class Main {

    public static int ret1, ret2, check, num, GCD, LCM;
    public static int[] visited;
    public static List<Integer> arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        GCD = sc.nextInt();
        LCM = sc.nextInt();

        ret1 = 1;
        ret2 = 1;
        num = LCM;
        check = 2*LCM;

        LCM /= GCD;
        num /= GCD;

        visited = new int[30];
        arr = new ArrayList<Integer>();

        for (int i = 2; i <= Math.sqrt(LCM) + 1; i++) {
            if (LCM % i == 0) {
                while (LCM % i == 0) {
                    LCM /= i;
                    arr.add(i);
                }
            }
        }

        solve(0, 0, 1);

        if (ret1 > ret2) {
            int tmp = ret1;
            ret1 = ret2;
            ret2 = tmp;
        }

        System.out.print(ret1 * GCD + " " + ret2 * GCD);
    }

    private static void solve(int lv, int st, int a) {
        if (a + num / a < check) {
            int aa = a;
            int b = num / a;
            while (aa % b != 0) {
                int tmp = aa % b;
                aa = b;
                b = tmp;
            }
            if (b == 1) {
                ret1 = a;
                ret2 = num / a;
                check = ret1 + ret2;
            }
        }

        if (lv == arr.size()) {
            return;
        }

        for (int i = st; i < arr.size(); i++) {

            solve(lv + 1, i + 1, a * arr.get(i));
        }
    }

}