import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        PriorityQueue<User> q = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            q.add(new User(Integer.parseInt(st.nextToken()), st.nextToken(), i));
        }

        while (!q.isEmpty()) {
            User u = q.poll();
            bw.write(u.getAge() + " " + u.getName() + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}

class User implements Comparable<User>{
    private int age;
    private String name;
    private int num;

    public User(int age, String name, int num) {
        this.age = age;
        this.name = name;
        this.num = num;
    }

    public int getAge() {
        return this.age;
    }

    public String getName() {
        return this.name;
    }

    public int getNum() {
        return this.num;
    }

    @Override
    public int compareTo(User u) {
        if (this.age > u.getAge()) return 1;
        else if (this.age == u.getAge()) {
            if (this.num > u.getNum()) return 1;
        }

        return -1;
    }
}