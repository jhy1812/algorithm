import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int tc = 1;

        while (true) {
            String s = sc.next();
            int cnt = 0;
            int check = 0;
            if (s.charAt(0) == '-') {
                break;
            }

            Stack<String> st = new Stack<String>();

            for (int i = 0; i < s.length(); i++) {
                if (st.size() == 0) {
                    if (s.charAt(i) == '}') {
                        cnt++;
                        st.add("{");
                    }
                    else {
                        st.add("{");
                    }
                    check++;
                } else {
                    if (st.peek().equals("{")) {
                        if (s.charAt(i) == '{') {
                            check++;
                            st.add("{");
                        }
                        else {
                            st.pop();
                            check--;
                        }
                    }
                }
            }
            int result = cnt + check / 2;
            System.out.println(tc + ". " + result);
            tc++;
        }
    }
}