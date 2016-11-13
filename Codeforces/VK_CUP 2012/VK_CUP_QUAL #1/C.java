import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(); in.nextLine();
		String cur = "/", s;
		for (int i = 0; i < n; i++) {
			s = in.nextLine();
			if (s.charAt(0) == 'p') {
				System.out.println(cur);
				continue;
			}
			s = s.substring(s.indexOf(" ") + 1);
			cur = get_cur(cur, s);
		}
	}

	static String get_cur(String cur, String s) {
		if (s.charAt(0) == '/') {
			cur = "/";
			s = s.substring(1);
		}
		if (!s.equals(""))
			s = s + "/";

		while (s.length() > 0) {
			String temp = s.substring(0, s.indexOf("/"));
			s = s.substring(s.indexOf("/") + 1);
			//System.out.println("temp=" + temp);
			if (temp.equals("..")) {
				cur = cur.substring(0, cur.length() - 1);
				cur = cur.substring(0, cur.lastIndexOf("/") + 1);
			} else
				cur = cur + temp + "/";
		}
		return cur;
	}
}