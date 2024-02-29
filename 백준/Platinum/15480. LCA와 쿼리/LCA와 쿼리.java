import java.io.*;
import java.util.*;

public class Main {
    public static int N, M, result;
    public static int[] lev;
    public static int[][] par;
    public static List<List<Integer>> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());

        lev = new int[N + 1];
        par = new int[N + 1][21];
        arr = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            arr.add(new ArrayList<Integer>());
        }

        for (int i = 1; i < N; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr.get(a).add(b);
            arr.get(b).add(a);
        }

        M = Integer.parseInt(bf.readLine());


        make_tree(0, 1, 0);

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            query(a, b, c);
            System.out.println(result);
        }
    }

    private static void make_tree(int lv, int node, int parent) {
        lev[node] = lv;
        par[node][0] = parent;
        int tmp = parent;
        for (int i = 1; i <= 20; i++) {
            par[node][i] = par[tmp][0];
            tmp = par[tmp][i];
        }

        for (int i = 0; i < arr.get(node).size(); i++) {
            int child = arr.get(node).get(i);
            if (parent == child) continue;
            make_tree(lv + 1, child, node);
        }
    }

    private static void query(int r, int u, int v) {
        int uCheck = 0; // 1 - 자식, 2 - 같은 가지인데 자식x, 3 - 다른 가지
        int vCheck = 0;

        int ru = 0;
        int rv = 0;

        int rr = r;
        int uu = u;
        int vv = v;
        if (lev[uu] > lev[r]) {
            if (lev[uu] != lev[r]) {
                for (int i = 20; i >= 0; i--) {
                    if (lev[par[uu][i]] >= lev[r]) {
                        if (par[uu][i] != 0) uu = par[uu][i];
                    }
                }
            }
            if (uu == r) {
                uCheck = 1;
            }
        }
        else {
            if (lev[uu] != lev[r]) {
                for (int i = 20; i >= 0; i--) {
                    if (lev[par[rr][i]] >= lev[u]) {
                        if (par[rr][i] != 0) rr = par[rr][i];
                    }
                }
            }
        }

        if (uCheck != 1) {
            if (uu != rr) {
                for (int i = 20; i >= 0; i--) {
                    if (par[uu][i] != par[rr][i]) {
                        uu = par[uu][i];
                        rr = par[rr][i];
                    }
                    ru = par[uu][i];
                }
            }
            else {
                ru = uu;
            }
            if (ru != 1) {
                uCheck = 2;
            }
            else {
                uCheck = 3;
            }
        }

        rr = r;

        if (lev[vv] > lev[r]) {
            if (lev[vv] != lev[r]) {
                for (int i = 20; i >= 0; i--) {
                    if (lev[par[vv][i]] >= lev[r]) {
                        if (par[vv][i] != 0) vv = par[vv][i];
                    }
                }
            }
            if (vv == r) {
                vCheck = 1;
            }
        }
        else {
            if (lev[vv] != lev[r]) {
                for (int i = 20; i >= 0; i--) {
                    if (lev[par[rr][i]] >= lev[v]) {
                        if (par[rr][i] != 0) rr = par[rr][i];
                    }
                }
            }
        }

        if (vCheck != 1) {
            if (vv != rr) {
                for (int i = 20; i >= 0; i--) {
                    if (par[vv][i] != par[rr][i]) {
                        vv = par[vv][i];
                        rr = par[rr][i];
                    }
                    rv = par[vv][i];
                }
            }
            else {
                rv = vv;
            }
            if (rv != 1) {
                vCheck = 2;
            }
            else {
                vCheck = 3;
            }
        }

        if (uCheck == 1 && vCheck == 1) {
            if (lev[u] < lev[v]) {
                int tmp = u;
                u = v;
                v = tmp;
            }
            if (lev[u] != lev[v]) {
                for (int i = 20; i >= 0; i--) {
                    if (lev[par[u][i]] >= lev[v]) {
                        if (par[u][i] != 0) u = par[u][i];
                    }
                }
            }
            if (u != v) {
                for (int i = 20; i >= 0; i--) {
                    if (par[u][i] != par[v][i]) {
                        u = par[u][i];
                        v = par[v][i];
                    }
                    result = par[u][i];
                }
            }
            else {
                result = u;
            }
        }
        else if (uCheck == 1 || vCheck == 1) {
            result = r;
        }
        else if (uCheck == 2 && vCheck == 2) {
            if (ru == rv) {
                if (lev[u] < lev[v]) {
                    int tmp = u;
                    u = v;
                    v = tmp;
                }
                if (lev[u] != lev[v]) {
                    for (int i = 20; i >= 0; i--) {
                        if (lev[par[u][i]] >= lev[v]) {
                            if (par[u][i] != 0) u = par[u][i];
                        }
                    }
                }
                if (u != v) {
                    for (int i = 20; i >= 0; i--) {
                        if (par[u][i] != par[v][i]) {
                            u = par[u][i];
                            v = par[v][i];
                        }
                        result = par[u][i];
                    }
                }
                else {
                    result = u;
                }
            }
            else if (lev[ru] > lev[rv]) {
                result = ru;
            }
            else {
                result = rv;
            }
        }
        else if (uCheck == 2) {
            result = ru;
        }
        else if (vCheck == 2) {
            result = rv;
        }
        else {
            if (lev[u] < lev[v]) {
                int tmp = u;
                u = v;
                v = tmp;
            }
            if (lev[u] != lev[v]) {
                for (int i = 20; i >= 0; i--) {
                    if (lev[par[u][i]] >= lev[v]) {
                        if (par[u][i] != 0) u = par[u][i];
                    }
                }
            }
            if (u != v) {
                for (int i = 20; i >= 0; i--) {
                    if (par[u][i] != par[v][i]) {
                        u = par[u][i];
                        v = par[v][i];
                    }
                    result = par[u][i];
                }
            }
            else {
                result = u;
            }
        }
    }
}