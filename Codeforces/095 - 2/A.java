import java.util.*;

public class A {
	public static void main(String[] args) {
		String s = new Scanner(System.in).nextLine();
		boolean flag = true;
		for (int i = 1; i < s.length(); i++)
			if (s.charAt(i) > 'Z')
				flag = false;
		if (!flag)
			System.out.println(s);
		else {
			if (s.charAt(0) > 'Z')
				System.out.println(Character.toUpperCase(s.charAt(0)) + s.substring(1).toLowerCase());
			else
				System.out.println(s.toLowerCase());
		}
	}
}