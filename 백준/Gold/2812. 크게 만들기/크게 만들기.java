import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        String num = br.readLine();
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < N; i++) {
            if (s.isEmpty()) s.add(num.charAt(i)-'0');
            else {
                int tmp = num.charAt(i)-'0';
                int last = s.peek();
                if (tmp > last && K != 0) {
                    while (!s.isEmpty() && K > 0) {
                        last = s.pop();
                        K--;
                        if (tmp <= last) {
                            K++;
                            s.add(last);
                            s.add(tmp);
                            break;
                        }
                        if (s.isEmpty() || K == 0) {
                            s.add(tmp);
                            break;
                        }
                    }
                }
                else {
                    s.add(tmp);
                }
            }
        }

        while (K-- > 0) {
            s.pop();
        }

        StringBuilder result = new StringBuilder();

        while (!s.isEmpty()) {
            result.append(s.pop().toString());
        }

        System.out.print(result.reverse());
    }
}