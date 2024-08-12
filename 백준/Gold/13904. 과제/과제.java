import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bf.readLine());
        int result = 0;
        int[] check = new int[1001];
        PriorityQueue<Pair> q = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            q.add(new Pair(a, b));
        }

        for (int i = 1; i <= 1000; i++) {
            if (q.isEmpty()) break;
            Pair p = q.poll();
            int d = p.getDay();
            int s = p.getScore();

            if (d >= i && check[i] == 0) {
                check[i] = s;
                result += s;
            }
            else {
                int day = 0;
                int sco = 100000;
                for (int j = 1; j <= d; j++) {
                    if (check[j] <= sco) {
                        sco = check[j];
                        day = j;
                    }
                }

                if (s > sco) {
                    result -= sco - s;
                    check[day] = s;
                }
            }

        }

        System.out.print(result);
    }
}

class Pair implements Comparable<Pair> {
    private int day;
    private int score;
    public Pair(int day, int score) {
        this.day = day;
        this.score = score;
    }

    public int getDay() {
        return this.day;
    }

    public int getScore() {
        return this.score;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.day > p.day) {
            return 1;
        }
        else if (this.day == p.day) {
            if (this.score < p.score) {
                return 1;
            }
        }

        return -1;
    }
}