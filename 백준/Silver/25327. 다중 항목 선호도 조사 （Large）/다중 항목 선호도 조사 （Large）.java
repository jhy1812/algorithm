import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        HashMap<String, Integer> num = new HashMap<String, Integer>();
        num.put("kor", 0);
        num.put("eng", 1);
        num.put("math", 2);

        num.put("apple", 0);
        num.put("pear", 1);
        num.put("orange", 2);

        num.put("red", 0);
        num.put("blue", 1);
        num.put("green", 2);

        int[][][] lst = new int[3][3][3];

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = num.get(st.nextToken());
            int b = num.get(st.nextToken());
            int c = num.get(st.nextToken());
            lst[a][b][c]++;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int result = 0;
            String fir = st.nextToken();
            String sec = st.nextToken();
            String trd = st.nextToken();
            if (fir.equals("-")) {
                for (int j = 0; j < 3; j++) {
                    if (sec.equals("-")) {
                        for (int k = 0; k < 3; k++) {
                            if (trd.equals("-")) {
                                for (int l = 0; l < 3; l++) {
                                    result += lst[j][k][l];
                                }
                            }
                            else {
                                int c = num.get(trd);
                                result += lst[j][k][c];
                            }
                        }
                    }
                    else {
                        int b = num.get(sec);
                        if (trd.equals("-")) {
                            for (int l = 0; l < 3; l++) {
                                result += lst[j][b][l];
                            }
                        }
                        else {
                            int c = num.get(trd);
                            result += lst[j][b][c];
                        }
                    }
                }
            }
            else {
                int a = num.get(fir);
                if (sec.equals("-")) {
                    for (int k = 0; k < 3; k++) {
                        if (trd.equals("-")) {
                            for (int l = 0; l < 3; l++) {
                                result += lst[a][k][l];
                            }
                        }
                        else {
                            int c = num.get(trd);
                            result += lst[a][k][c];
                        }
                    }
                }
                else {
                    int b = num.get(sec);
                    if (trd.equals("-")) {
                        for (int l = 0; l < 3; l++) {
                            result += lst[a][b][l];
                        }
                    }
                    else {
                        int c = num.get(trd);
                        result += lst[a][b][c];
                    }
                }
            }
            System.out.println(result);
        }
    }
}