import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(); in.nextLine();
		String cur_num = in.nextLine();
		for (int i = 1; i < n; i++) {
			String s = in.nextLine();
			int t = Math.min(cur_num.length(), s.length());
			for (int j = 0; j < t; j++)
				if (cur_num.charAt(j) != s.charAt(j)) {
					cur_num = cur_num.substring(0, j);
					break;
				}
		}
		System.out.println(cur_num.length());
	}
}