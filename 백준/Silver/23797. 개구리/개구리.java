import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        Stack<Character> st = new Stack<Character>();
        int kret = 0;
        int pret = 0;
        int pcnt = 0;
        int kcnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'P') {
                if (kcnt > 0) {
                    kcnt--;
                }
                else {
                    pcnt++;
                    pret = Math.max(pret, pcnt);
                }
            }
            else {
                if (pcnt > 0) {
                    pcnt--;
                }
                else {
                    kcnt++;
                    kret = Math.max(kret, kcnt);
                }
            }
        }

        System.out.print(pret + kret);
    }
}