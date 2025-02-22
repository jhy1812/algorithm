import java.io.*;
import java.util.*;

public class Main {

    public static int[] month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[13];

        for (int i = 1; i <= 12; i++) {
            arr[i] = arr[i-1]+month[i-1];
        }

        int start = arr[2];
        int end = arr[2]+1;
        int std = arr[11]+1;
        int cnt = 0;
        PriorityQueue<Pair> q = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            q.add(new Pair(arr[a-1]+b, arr[c-1]+d));
        }

        while (!q.isEmpty()) {
            int tmp = 0;
            cnt++;
            while (!q.isEmpty()) {
                Pair p = q.poll();
                if (end >= p.getS()) tmp = Math.max(tmp, p.getE());
                else {
                    q.add(p);
                    break;
                }
            }


            end = Math.max(end, tmp);

            if (end >= std) {
                System.out.print(cnt);
                break;
            }

            if (tmp == 0 || q.isEmpty()) {
                System.out.print(0);
                break;
            }
        }
    }
}

class Pair implements Comparable<Pair> {

    private int s;
    private int e;
    public Pair(int s, int e) {
        this.s = s;
        this.e = e;
    }
    public int getS() {
        return this.s;
    }

    public int getE() {
        return this.e;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.s > p.getS()) return 1;
        return -1;
    }
}