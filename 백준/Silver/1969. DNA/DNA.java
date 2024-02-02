import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        String result = "";

        int[][] dna = new int[M][4];
        HashMap<Character, Integer> check = new HashMap<Character, Integer>();
        HashMap<Integer, Character> rev = new HashMap<Integer, Character>();

        check.put('A', 0);
        check.put('C', 1);
        check.put('G', 2);
        check.put('T', 3);

        rev.put(0, 'A');
        rev.put(1, 'C');
        rev.put(2, 'G');
        rev.put(3, 'T');

        for (int i = 0; i < N; i++) {
            String tmp = sc.next();
            for (int j = 0; j < M; j++) {
                dna[j][check.get(tmp.charAt(j))]++;
            }
        }

        int summ = 0;

        for (int i = 0; i < M; i++) {
            int tmp = 0;
            int idx = 0;
            for (int j = 0; j < 4; j++) {
                if (tmp < dna[i][j]) {
                    tmp = dna[i][j];
                    idx = j;
                }
            }
            summ += N - tmp;
            result += rev.get(idx);
        }

        System.out.println(result);
        System.out.print(summ);
    }
}