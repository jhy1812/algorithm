import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());

        long ca = Long.parseLong(st.nextToken());
        long cs = Long.parseLong(st.nextToken());
        long ccp = Long.parseLong(st.nextToken());
        long ccr = Long.parseLong(st.nextToken());
        long cas = Long.parseLong(st.nextToken());

        long cbe = calc(ca, cs, ccp, ccr, cas);

        st = new StringTokenizer(br.readLine());

        long pa = Long.parseLong(st.nextToken());
        long ps = Long.parseLong(st.nextToken());
        long pcp = Long.parseLong(st.nextToken());
        long pcr = Long.parseLong(st.nextToken());
        long pas = Long.parseLong(st.nextToken());

        long pbe = calc(pa, ps, pcp, pcr, pas);

        st = new StringTokenizer(br.readLine());

        long cwa = Long.parseLong(st.nextToken());
        long cws = Long.parseLong(st.nextToken());
        long cwcp = Long.parseLong(st.nextToken());
        long cwcr = Long.parseLong(st.nextToken());
        long cwas = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());


        long pwa = Long.parseLong(st.nextToken());
        long pws = Long.parseLong(st.nextToken());
        long pwcp = Long.parseLong(st.nextToken());
        long pwcr = Long.parseLong(st.nextToken());
        long pwas = Long.parseLong(st.nextToken());

        ca -= cwa - pwa;
        cs -= cws - pws;
        ccp -= cwcp - pwcp;
        ccr -= cwcr - pwcr;
        cas -= cwas - pwas;

        pa += cwa - pwa;
        ps += cws - pws;
        pcp += cwcp - pwcp;
        pcr += cwcr - pwcr;
        pas += cwas - pwas;

        long caf = calc(ca, cs, ccp, ccr, cas);
        long paf = calc(pa, ps, pcp, pcr, pas);

        if (cbe > caf) {
            System.out.println("-");
        }
        else if (cbe < caf) {
            System.out.println("+");
        }
        else {
            System.out.println("0");
        }

        if (pbe > paf) {
            System.out.print("-");
        }
        else if (pbe < paf) {
            System.out.print("+");
        }
        else {
            System.out.print("0");
        }
    }

    static private long calc(long a, long s, long cp, long cr, long as) {

        return a * (100L + s) * ((10000L - Math.min(cp*100L, 10000L)) + Math.min(cp, 100L) * cr) * (100 + as);
    }
}