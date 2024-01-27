import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String result = "";
        int odd_idx = 0;
        int odd_check = 0;
        int[] num = new int[26];

        for (int i = 0; i < s.length(); i++) {
            num[s.charAt(i) - 'A']++;
        }

        for (int i = 0; i < 26; i++) {
            if (num[i]%2 == 1) {
                odd_check++;
                odd_idx = i;
            }
        }

        if (s.length() % 2 == 0) {
            if (odd_check > 0) {
                System.out.print("I'm Sorry Hansoo");
            }
            else {
                for (int i = 25; i >= 0; i--) {
                    char tmp = (char) (i + 65);
                    for (int j = 0; j < num[i] / 2; j++) {
                        result = tmp + result + tmp;
                    }
                }
            }
        }
        else {
            if (odd_check != 1) {
                System.out.print("I'm Sorry Hansoo");
            }
            else {
                result = result + (char) (odd_idx + 65);
                for (int i = 25; i >= 0; i--) {
                    char tmp = (char) (i + 65);
                    for (int j = 0; j < num[i] / 2; j++) {
                        result = tmp + result + tmp;
                    }
                }
            }
        }

        System.out.print(result);
    }
}