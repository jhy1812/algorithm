import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String X = sc.next();
        int lens = X.length();
        int ret1 = 0;
        int ret2 = 0;
        int ret3 = 0;
        int result = 0;
        Stack<Character> st1 = new Stack<Character>();
        Stack<Character> st2 = new Stack<Character>();
        Stack<Character> st3 = new Stack<Character>();
        HashMap<Character, Character> check = new HashMap<>();
        check.put('K', 'A');
        check.put('S', 'K');
        check.put('A', 'S');
        st1.add('K');
        st2.add('S');
        st3.add('A');
        for (int i = 0; i < lens; i++) {
            if (st1.peek() == check.get(X.charAt(i))) {
                st1.add(X.charAt(i));
            }
            if (st2.peek() == check.get(X.charAt(i))) {
                st2.add(X.charAt(i));
            }
            if (st3.peek() == check.get(X.charAt(i))) {
                st3.add(X.charAt(i));
            }
        }

        if (st1.size() > lens) {
            ret1 = 2;
        }
        else {
            ret1 += 2 * (lens - st1.size() + 1);
        }
        if (st2.size() > lens) {
            ret2 = 2;
        }
        else if (st2.size() == lens) {
            ret2 = 4;
        }
        else {
            ret2 += 2 * (lens - st2.size() + 1);
        }
        ret3 += 2 * (lens - st3.size() + 1);



        result = Math.min(ret1, Math.min(ret2, ret3));

        System.out.print(result);
    }
}