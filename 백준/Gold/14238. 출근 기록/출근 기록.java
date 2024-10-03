import java.io.*;
import java.util.*;

public class Main {

    public static boolean check = false;
    public static String S, ret;
    public static boolean dp[][][][];
    public static char[] result;
    public static HashMap<Character, Integer> record;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        S = br.readLine();
        ret = "";
        record = new HashMap<>();

        int a = 0;
        int b = 0;
        int c = 0;

        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'A') a++;
            else if (S.charAt(i) == 'B') b++;
            else c++;
        }

        record.put('A', a);
        record.put('B', b);
        record.put('C', c);

        dp = new boolean[S.length()+1][S.length()+1][S.length()+1][5];
        result = new char[S.length()];

        dfs(0, 0, 0, 0, 0);

        if (check) System.out.print(ret);
        else System.out.print(-1);
    }

    public static void dfs(int lv, int a, int b, int c, int state) {
        if (check) return;
        if (lv == S.length()) {
            for (int i = 0; i < S.length(); i++) {
                ret += result[i];
            }
            check = true;
            return;
        }

        if (state == 0) {
            if (c+1 <= record.get('C')) {
                if (!dp[a][b][c+1][2]) {
                    dp[a][b][c+1][2] = true;
                    result[lv] = 'C';
                    dfs(lv+1, a, b, c+1, 2);
                }
            }
            if (b+1 <= record.get('B')) {
                if (!dp[a][b+1][c][1]) {
                    dp[a][b+1][c][1] = true;
                    result[lv] = 'B';
                    dfs(lv+1, a, b+1, c, 1);
                }
            }
            if (a+1 <= record.get('A')) {
                if (!dp[a+1][b][c][0]) {
                    dp[a+1][b][c][0] = true;
                    result[lv] = 'A';
                    dfs(lv+1, a+1, b, c, 0);
                }
            }
        }
        else if (state == 1) {
            if (c+1 <= record.get('C')) {
                if (!dp[a][b][c+1][2]) {
                    dp[a][b][c+1][2] = true;
                    result[lv] = 'C';
                    dfs(lv+1, a, b, c+1, 2);
                }
            }
            if (a+1 <= record.get('A')) {
                if (!dp[a+1][b][c][0]) {
                    dp[a+1][b][c][0] = true;
                    result[lv] = 'A';
                    dfs(lv+1, a+1, b, c, 0);
                }
            }
        }
        else if (state == 2) {
            if (b+1 <= record.get('B')) {
                if (!dp[a][b+1][c][4]) {
                    dp[a][b+1][c][4] = true;
                    result[lv] = 'B';
                    dfs(lv+1, a, b+1, c, 4);
                }
            }
            if (a+1 <= record.get('A')) {
                if (!dp[a+1][b][c][3]) {
                    dp[a+1][b][c][3] = true;
                    result[lv] = 'A';
                    dfs(lv+1, a+1, b, c, 3);
                }
            }
        }
        else if (state == 3) {
            if (b+1 <= record.get('B')) {
                if (!dp[a][b+1][c][1]) {
                    dp[a][b+1][c][1] = true;
                    result[lv] = 'B';
                    dfs(lv+1, a, b+1, c, 1);
                }
            }
            if (a+1 <= record.get('A')) {
                if (!dp[a+1][b][c][0]) {
                    dp[a+1][b][c][0] = true;
                    result[lv] = 'A';
                    dfs(lv+1, a+1, b, c, 0);
                }
            }
        }
        else if (state == 4) {
            if (a+1 <= record.get('A')) {
                if (!dp[a+1][b][c][0]) {
                    dp[a+1][b][c][0] = true;
                    result[lv] = 'A';
                    dfs(lv+1, a+1, b, c, 0);
                }
            }
        }
    }
}