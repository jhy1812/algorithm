import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int co = 0;
        int ek = 0;
        int[] score = {13, 7, 5, 3, 3, 2};

        for (int i = 0; i < 6; i++) {
            co += Integer.parseInt(st.nextToken()) * score[i];
        }

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 6; i++) {
            ek += Integer.parseInt(st.nextToken()) * score[i];
        }

        if (co >= ek+2) {
            System.out.print("cocjr0208");
        }
        else {
            System.out.print("ekwoo");
        }
    }
}