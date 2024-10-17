import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        int[] arr = new int[26];
        PriorityQueue<Pair> q = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            String word = br.readLine();
            int val = 1;
            for (int j = word.length()-1; j >= 0; j--) {
                arr[word.charAt(j)-'A'] += val;
                val *= 10;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                q.add(new Pair((char)(i+65), arr[i]));
            }
        }
        int num = 9;
        while (!q.isEmpty()) {
            Pair p = q.poll();
            result += arr[p.getA()-'A']*num--;
        }

        System.out.print(result);
    }
}

class Pair implements Comparable<Pair> {

    private char a;
    private int n;

    public Pair(char a, int n) {
        this.a = a;
        this.n = n;
    }

    public char getA() {
        return this.a;
    }

    public int getN() {
        return this.n;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.n < p.getN()) return 1;
        return -1;
    }
}