import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int h, m;
		h = scan.nextInt();
		m = scan.nextInt();
		
		if (m - 45 < 0) {
			h = (h+23)%24;
		}
		
		m = (m+15)%60;
		
		System.out.print(h);
		System.out.print(" ");		
		System.out.print(m);
	}
}