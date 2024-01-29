import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String p = sc.next();

        int[][] arr = new int[s.length()][p.length()];
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < p.length(); j++) {
                if (i == 0 || j == 0) {
                    if (s.charAt(i) == p.charAt(j)) {
                        arr[i][j] = 1;
                    }
                }
                else {
                    if (s.charAt(i) == p.charAt(j)) {
                        arr[i][j] = arr[i - 1][j - 1] + 1;
                    }
                }
                result = Math.max(result, arr[i][j]);
            }
        }

        System.out.print(result);
    }
}