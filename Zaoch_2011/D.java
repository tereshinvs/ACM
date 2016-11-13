import java.math.*;
import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger l = readNumber(in), a = readNumber(in), b = readNumber(in);
		BigInteger lcd = (a.multiply(b)).divide(a.gcd(b));
		System.out.println(l.divide(lcd).subtract(l.mod(lcd).equals(BigInteger.ZERO) ? BigInteger.ONE : BigInteger.ZERO));
	}

	static BigInteger readNumber(Scanner in) {
		String s = in.nextLine();
		if (s.charAt(0) == '.')
			s = "0" + s;
		return new BigDecimal(s).multiply(BigDecimal.valueOf(1000000000)).toBigInteger();
	}
}