import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        Stack<Character> st;

        for (int tc = 1; tc <= T; tc++) {
            String s = sc.next();
            st = new Stack<Character>();

            for (int i = 0; i < s.length(); i++) {
                if (st.empty()) {
                    st.add(s.charAt(i));
                }
                else {
                    if (st.peek() == '0' || st.peek() == '1') {
                        st.pop();
                        st.add('1');
                    }
                    else {
                        st.add(s.charAt(i));
                    }
                }
            }

            char ch = st.pop();
            int len = st.size();
            for (int i = 0; i < len; i++) {
                char tmp = st.pop();
                if (ch == '0') {
                    ch = '1';
                }
                else {
                    ch = '0';
                }
            }
            System.out.println(ch);
        }
    }
}