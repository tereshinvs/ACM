import java.math.*;

public class bruteforce {
	public static void main(String[] args) {
		for (BigInteger i = BigInteger.ONE, sqr_i = BigInteger.ONE; true;
			sqr_i = sqr_i.add(i.add(i).add(BigInteger.ONE)), i = i.add(BigInteger.ONE))
			if (is_palindrome(i) && is_palindrome(sqr_i))
				System.out.println(i + "               " + sqr_i);
	}

	static boolean is_palindrome(BigInteger t) {
		String str = t.toString();
		int lng = str.length() / 2, full = str.length();
		for (int i = 0; i < lng; i++)
			if (str.charAt(i) != str.charAt(full - i - 1))
				return false;
		return true;
	}
}