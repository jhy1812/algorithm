import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        HashMap<Integer, Integer> check = new HashMap<Integer, Integer>();
        List<Integer> dp = new ArrayList<Integer>();

        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();
            check.put(tmp, i);
        }

        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();
            if (i == 0) {
                dp.add(check.get(tmp));
            }
            else {
                int last = dp.get(dp.size() - 1);
                tmp = check.get(tmp);
                if (last < tmp) {
                    dp.add(tmp);
                }
                else {
                    int left = 0;
                    int right = dp.size() - 1;
                    int mid;
                    int idx = 0;
                    while (left <= right) {
                        mid = (left + right) / 2;
                        if (tmp <= dp.get(mid)) {
                            idx = mid;
                            right = mid - 1;
                        }
                        else {
                            left = mid + 1;
                        }
                    }
                    dp.set(idx, tmp);
                }
            }
        }
        System.out.print(dp.size());
    }
}