import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int tc = 1; tc <= T; tc++) {
            String fi = sc.next();
            String se = sc.next();

            int fiq = 0;
            int fiz = 0;
            int fio = 0;

            int sez = 0;
            int seo = 0;

            int qo = 0;
            int match = 0;

            for (int i = 0; i < fi.length(); i++) {
                if (fi.charAt(i) == '0') {
                    fiz++;
                }
                else if (fi.charAt(i) == '1') {
                    fio++;
                    if (se.charAt(i) == '1') {
                        match++;
                    }
                }
                else {
                    fiq++;
                    if (se.charAt(i) == '1') {
                       qo++;
                    }
                }
                if (se.charAt(i) == '0') {
                    sez++;
                }
                else {
                    seo++;
                }
            }
            System.out.print("Case " + tc + ": ");
            if (fio > seo) {
                System.out.println(-1);
            }
            else {
                int result = 0;
                fio -= match;
                seo -= match;
                if (fio < seo) {
                    if (qo > seo - fio) {
                        result += seo-fio;
                        fiq -= seo - fio;
                        result += fiq;
                        result += fio;
                    }
                    else if (qo < seo - fio) {
                        result += qo;
                        result += fio;
                        int tmp = seo - qo - fio;
                        result += tmp;
                        fiq -= qo;
                        result += fiq;
                    }
                    else {
                        result += qo;
                        result += fio;
                        fiq -= qo;
                        result += fiq;
                    }
                }
                else {
                    result += seo;
                    result += fiq;
                }
                System.out.println(result);
            }
        }
    }
}