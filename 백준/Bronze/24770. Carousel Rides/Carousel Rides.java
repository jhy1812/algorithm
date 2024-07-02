import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));


        while (true) {
            StringTokenizer st = new StringTokenizer(bf.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int tickets = 0;
            int cost = 0;

            if (n == 0 && m == 0) {
                break;
            }

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(bf.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                if (a > m) {
                    continue;
                }

                if (tickets == 0 && cost == 0) {
                    tickets = a;
                    cost = b;
                    continue;
                }

                int be = cost * a;
                int af = b * tickets;

                if (af < be) {
                    tickets = a;
                    cost = b;
                }
                else if (af == be) {
                    if (a > tickets) {
                        tickets = a;
                        cost = b;
                    }
                }
            }
            if (tickets == 0 && cost == 0) {
                System.out.println("No suitable tickets offered");
                continue;
            }
            System.out.println("Buy " + tickets + " tickets for $" + cost);
        }
    }
}