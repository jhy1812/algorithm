import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while (true) {
            st = new StringTokenizer(br.readLine());

            int[][] arr = new int[4][2];
            arr[0][0] = Integer.parseInt(st.nextToken());
            arr[1][0] = Integer.parseInt(st.nextToken());
            arr[2][0] = Integer.parseInt(st.nextToken());
            arr[3][0] = Integer.parseInt(st.nextToken());

            if (arr[0][0] == 0 && arr[1][0] == 0 && arr[2][0] == 0 && arr[3][0] == 0) {
                break;
            }
            int cnt = 0;

            while (true) {
                if ((arr[0][cnt%2] == arr[1][cnt%2]) && (arr[2][cnt%2] == arr[3][cnt%2]) && (arr[0][cnt%2] == arr[3][cnt%2])) {
                    break;
                }
                arr[0][(cnt + 1)%2] = Math.abs(arr[0][cnt%2] - arr[1][cnt%2]);
                arr[1][(cnt + 1)%2] = Math.abs(arr[1][cnt%2] - arr[2][cnt%2]);
                arr[2][(cnt + 1)%2] = Math.abs(arr[2][cnt%2] - arr[3][cnt%2]);
                arr[3][(cnt + 1)%2] = Math.abs(arr[3][cnt%2] - arr[0][cnt%2]);

                cnt++;
            }

            System.out.println(cnt);
        }
    }
}