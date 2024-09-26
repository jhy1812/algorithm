import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static Stack<Rt> ht;
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        ht = new Stack<>();

        long result = (long) Integer.parseInt(br.readLine());
        ht.add(new Rt((int) result, 1));

        for (int i = 1; i < N; i++) {
            int tmp = Integer.parseInt(br.readLine());
            if (ht.peek().getH() < tmp) {
                ht.add(new Rt(tmp, 1));
            }
            else if (ht.peek().getH() == tmp) {
                int w = ht.pop().getW();
                ht.add(new Rt(tmp, ++w));
            }
            else {
                int h = 0;
                int w = 0;
                while (!ht.isEmpty()) {
                    Rt rt = ht.pop();
                    w += rt.getW();
                    h = rt.getH();

                    result = Math.max(result, (long) w*h);

                    if (ht.isEmpty()) {
                        ht.add(new Rt(tmp, w+1));
                        break;
                    }
                    else if (ht.peek().getH() == tmp) {
                        int ww = ht.pop().getW();
                        ht.add(new Rt(tmp, ww+w+1));
                        break;
                    }
                    else if (ht.peek().getH() < tmp) {
                        ht.add(new Rt(tmp, w+1));
                        break;
                    }
                }
            }
        }

        int w = 0;
        int h = 0;

        while (!ht.isEmpty()) {
            Rt rt = ht.pop();
            w += rt.getW();
            h = rt.getH();
            result = Math.max(result, (long) w*h);
        }

        System.out.print(result);
    }
}

class Rt {
    private int h;
    private int w;

    public Rt(int h, int w) {
        this.h = h;
        this.w = w;
    }

    public int getH() {
        return this.h;
    }

    public int getW() {
        return this.w;
    }
}