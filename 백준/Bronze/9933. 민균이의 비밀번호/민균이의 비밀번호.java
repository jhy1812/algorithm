import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());
        List<String> lst = new ArrayList<String>();
        int l = 0;
        char c = 'a';

        for (int i = 0; i < N; i++) {
            String tmp = bf.readLine();
            int check = 0;
            for (int j = 0; j < tmp.length() / 2; j++) {
                if (tmp.charAt(j) != tmp.charAt(tmp.length() - j - 1)) {
                    check = 1;
                    break;
                }
            }
            if (check == 0) {
                l = tmp.length();
                c = tmp.charAt(tmp.length() / 2);
            }
            else {
                lst.add(tmp);
            }
        }

        if (l == 0) {
            int flag = 0;
            for (int i = 0; i < N; i++) {
                String a = lst.get(i);
                for (int j = i + 1; j < N; j++) {
                    String b = lst.get(j);
                    if (a.length() != b.length()) {
                        continue;
                    }
                    int check = 0;
                    for (int k = 0; k < a.length() / 2; k++) {
                        if (a.charAt(k) != b.charAt(a.length() - k - 1)) {
                            check = 1;
                            break;
                        }
                    }
                    if (check == 0) {
                        flag = 1;
                        l = a.length();
                        c = a.charAt(a.length() / 2);
                        break;
                    }
                }
                if (flag == 1) {
                    break;
                }
            }
        }
        System.out.printf("%d %c%n", l, c);
    }
}