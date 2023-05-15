import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int h, m, c;
		
		h = scan.nextInt();
		m = scan.nextInt();
		c = scan.nextInt();
		
		h = (h + (m+c)/60)%24;
		m = (m+c)%60;
		
		System.out.printf("%d %d", h, m);
	}
}