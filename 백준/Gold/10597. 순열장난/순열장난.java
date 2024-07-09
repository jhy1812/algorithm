import java.io.*;
import java.util.*;

public class Main {
    static String s;
    static public int mx;
    static public int flag;
    static public int len;
    static public int[] check;
    static public int[] result;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        s = bf.readLine();
        len = s.length();
        if (s.length() < 10) {
            mx = s.length();
        }
        else {
            int tmp = s.length();
            tmp -= 9;
            tmp /= 2;
            mx = tmp + 9;
        }
        check = new int[mx + 1];
        result = new int[mx + 1];

        solve(0, 0);

        for (int i = 0; i < mx; i++) {
            System.out.print(result[i] + " ");
        }
    }

    static private void solve(int n, int lv) {
        if (flag == 1) {
            return;
        }
        if (lv == mx) {
            flag = 1;
            return;
        }

        if (n >= len) {
            return;
        }

        int tmp = Integer.parseInt(s.substring(n, n + 1));
        if (tmp == 0) {
            return;
        }
        if (check[tmp] == 0) {
            check[tmp] = 1;
            result[lv] = tmp;
            solve(n + 1, lv + 1);
            check[tmp] = 0;
        }
        if (flag == 1) {
            return;
        }
        if (n + 1 < len) {
            tmp = Integer.parseInt(s.substring(n, n + 2));
            if (tmp > mx) {
                return;
            }
            if (check[tmp] == 0) {
                check[tmp] = 1;
                result[lv] = tmp;
                solve(n + 2, lv + 1);
                check[tmp] = 0;
            }
        }
    }
}