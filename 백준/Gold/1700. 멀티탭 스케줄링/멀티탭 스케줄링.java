import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int num = 0;
        int[] ele = new int[K + 1];
        int[] check = new int[K+1];
        boolean[] plug = new boolean[K + 1];
        int result = 0;
        Queue<Integer> q = new LinkedList<>();
        PriorityQueue<Pair> mul = new PriorityQueue<>();
        List<List<Integer>> arr = new ArrayList<>();

        for (int i = 0; i <= K; i++) {
            arr.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= K; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            ele[tmp]++;
            check[tmp]++;
            q.add(tmp);
            arr.get(tmp).add(i);
        }

        while (!q.isEmpty()) {
            int tmp = q.poll();
            ele[tmp]--;
            if (num < N) {
                if (!plug[tmp]){
                    num++;
                    plug[tmp] = true;
                }
            }
            else {
                if (!plug[tmp]) {
                    Pair p = mul.poll();
                    result++;
                    plug[p.getName()] = false;
                    plug[tmp] = true;
                }
            }
            if (ele[tmp] == 0) {
                mul.add(new Pair(tmp, K+1));
            }
            else {
                mul.add(new Pair(tmp, arr.get(tmp).get(check[tmp]-ele[tmp])));
            }
        }

        System.out.print(result);
    }
}

class Pair implements Comparable<Pair> {
    private int name;
    private int num;

    public Pair(int name, int num) {
        this.name = name;
        this.num = num;
    }

    public int getName() {
        return this.name;
    }

    public int getNum() {
        return this.num;
    }

    @Override
    public int compareTo(Pair p) {
        if (this.num < p.getNum()) return 1;
        if (this.name == p.getName()) {
            if (this.num < p.getNum()) return 1;
        }
        return -1;
    }
}