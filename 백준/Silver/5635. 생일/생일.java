import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        String old = "";
        String young = "";
        int od = 0;
        int om = 0;
        int oy = 0;
        int yd = 0;
        int ym = 0;
        int yy = 0;

        for (int i = 0; i < n; i++) {
            String tmp = sc.next();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            if (i == 0) {
                old = tmp;
                young = tmp;
                od = a;
                om = b;
                oy = c;
                yd = a;
                ym = b;
                yy = c;
                continue;
            }

            if (oy > c) {
                old = tmp;
                oy = c;
                om = b;
                od = a;
            }
            else if (oy == c) {
                if (om > b) {
                    old = tmp;
                    oy = c;
                    om = b;
                    od = a;
                }
                else if (om == b) {
                    if (od > a) {
                        old = tmp;
                        oy = c;
                        om = b;
                        od = a;
                    }
                }
            }
            if (yy < c) {
                young = tmp;
                yy = c;
                ym = b;
                yd = a;
            }
            else if (yy == c) {
                if (ym < b) {
                    young = tmp;
                    yy = c;
                    ym = b;
                    yd = a;
                }
                else if (ym == b) {
                    if (yd < a) {
                        young = tmp;
                        yy = c;
                        ym = b;
                        yd = a;
                    }
                }

            }
        }

        System.out.println(young);
        System.out.print(old);
    }
}