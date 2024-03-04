import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int W = sc.nextInt();

        W *= 2;

        W = (int)Math.sqrt(W);

        System.out.print(4 * W);
    }
}