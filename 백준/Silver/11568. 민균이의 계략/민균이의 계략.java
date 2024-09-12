import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        List<Integer> lst = new ArrayList<Integer>();

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        lst.add(arr[0]);
        int len = 0;

        for (int i = 1; i < N; i++) {
            if (lst.get(len) < arr[i]) {
                lst.add(arr[i]);
                len++;
            }
            else if (lst.get(len) > arr[i]) {
                int s = 0;
                int e = len;

                while (s < e) {
                    int mid = s + (e - s) / 2;
                    if (lst.get(mid) < arr[i]) {
                        s = mid + 1;
                    } else {
                        e = mid;
                    }
                }
                lst.set(s, arr[i]);
            }
        }
        System.out.print(len+1);
    }
}