import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String dummy = sc.nextLine();

        for (int i = 0; i < n; i++) {
            String tmp = sc.nextLine();
            int check = 0;
            for (int j = 0; j < tmp.length() / 2; j++) {
                char a = tmp.charAt(j);
                char b = tmp.charAt(tmp.length() - j - 1);

                if (65 <= (int) a && (int) a <= 90) {
                    a = (char) ((int) a + 32);
                }
                if (65 <= (int) b && (int) b <= 90) {
                    b = (char) ((int) b + 32);
                }

                if (a != b) {
                    check = 1;
                    break;
                }
            }
            if (check == 1) {
                System.out.println("No");
            }
            else {
                System.out.println("Yes");
            }
        }
    }
}