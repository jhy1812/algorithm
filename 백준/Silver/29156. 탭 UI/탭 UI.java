import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        double[] hap = new double[N + 1];
        double[] cen = new double[N + 1];

        for (int i = 1; i <= N; i++) {
            double tmp = Double.parseDouble(br.readLine());
            hap[i] = hap[i - 1] + tmp;
            cen[i] = hap[i - 1] + tmp / 2;
        }

        double L = Double.parseDouble(br.readLine());
        L /= 2;
        int Q = Integer.parseInt(br.readLine());

        for (int i = 0; i < Q; i++) {
            int tmp = Integer.parseInt(br.readLine());
            if (2 * L >= hap[N]) {
                sb.append("0.00\n");
            } else if (L >= cen[tmp]) {
                sb.append("0.00\n");
            } else if (L >= hap[N] - cen[tmp]) {
                BigDecimal position = BigDecimal.valueOf(hap[N] - 2 * L).setScale(2, RoundingMode.FLOOR);
                sb.append(position).append("\n");
            } else {
                BigDecimal position = BigDecimal.valueOf(cen[tmp] - L).setScale(2, RoundingMode.FLOOR);
                sb.append(position).append("\n");
            }
        }

        System.out.print(sb.toString());
    }
}
