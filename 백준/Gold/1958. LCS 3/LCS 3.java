import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();
        String c = sc.next();

        int result = 0;
        int [][][] arr = new int[a.length() + 1][b.length() + 1][c.length() + 1];

        for (int i = 1; i <= a.length(); i++) {
            for (int j = 1; j <= b.length(); j++) {
                for (int k = 1; k <= c.length(); k++) {

                    if (a.charAt(i - 1) == b.charAt(j - 1) && b.charAt(j - 1) == c.charAt(k - 1)) {
                        arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;

                    }
                    else {
                        arr[i][j][k] = Math.max(arr[i - 1][j][k], arr[i][j - 1][k]);
                        arr[i][j][k] = Math.max(arr[i][j][k], arr[i][j][k - 1]);
                        arr[i][j][k] = Math.max(arr[i][j][k], arr[i - 1][j][k - 1]);
                        arr[i][j][k] = Math.max(arr[i][j][k], arr[i - 1][j - 1][k]);
                        arr[i][j][k] = Math.max(arr[i][j][k], arr[i][j - 1][k - 1]);
                        arr[i][j][k] = Math.max(arr[i][j][k], arr[i - 1][j - 1][k - 1]);
                    }
                    result = Math.max(result, arr[i][j][k]);
                }
            }
        }

        System.out.print(result);
    }
}