import java.util.*;
import java.math.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt(), t = in.nextInt();
		BigInteger res = BigInteger.ZERO;
		for (int i = 4; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (i + j != t)
					continue;
				res = res.add(c(n, i).multiply(c(m, j)));
			}
		System.out.println(res);
	}

	static BigInteger c(int n, int k) {
		return fact(n).divide(fact(k)).divide(fact(n-k));
	}

	static BigInteger fact(int t) {
		BigInteger res = BigInteger.ONE;
		for (int i = 1; i <= t; i++)
			res = res.multiply(BigInteger.valueOf(i));
		return res;
	}
}