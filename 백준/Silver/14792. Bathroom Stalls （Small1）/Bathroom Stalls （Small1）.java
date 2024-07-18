import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            PriorityQueue<Node> q = new PriorityQueue<>();
            q.add(new Node(0, N + 1));

            int ls = 0;
            int rs = 0;

            for (int i = 0; i < K; i++) {
                Node node = q.poll();
                int l = node.getL();
                int r = node.getR();
                int mid = (l + r) / 2;

                ls = mid - l - 1;
                rs = r - mid - 1;
                if (mid - l != 1) {
                    q.add(new Node(l, mid));
                }
                if (r - mid != 1) {
                    q.add(new Node(mid, r));
                }
            }

            System.out.println("Case #" + tc + ": " + Math.max(ls, rs) + " " + Math.min(ls, rs));
        }
    }
}

class Node implements Comparable<Node> {
    private int l;
    private int r;
    private int dis;

    public Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.dis = r - l;
    }

    public int getL() {
        return this.l;
    }

    public int getR() {
        return this.r;
    }

    public int getDis() {
        return this.dis;
    }

    @Override
    public int compareTo(Node node) {
        if (this.dis < node.dis) {
            return 1;
        }
        else if (this.dis == node.dis) {
            if (this.l > node.l) {
                return 1;
            }
        }
        return -1;
    }
}