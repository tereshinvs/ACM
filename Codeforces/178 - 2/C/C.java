import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt(), a[] = new int[m];
		for (int i = 0; i < m; i++)
			a[i] = in.nextInt();
		Arrays.sort(a);

/*		BigInteger res = fact(m + 1).divide(fact(a[0] - 1));
		for (int i = 1; i < m; i++)
			res = res.divide(fact(a[i] - a[i - 1] - 1));
		res = res.divide(fact(n - a[m - 1]));*/
		int k = 0;
		k += a[0] - 1;
		for (int i = 1; i < m; i++)
			k += a[i] - a[i - 1] - 1;
		k += n - a[m - 1];

		BigInteger res = fact(k);
		if (a[0] > 1)
			res = res.divide(fact(a[0] - 1));
		for (int i = 1; i < m; i++)
			if (a[i] - a[i - 1] > 1)
				res = res.divide(fact(a[i] - a[i - 1] - 1));
		if (a[m - 1] < n)
			res = res.divide(fact(n - a[m - 1]));

		//System.out.println(res);

		BigInteger TWO = BigInteger.ONE.add(BigInteger.ONE);
		/*if (a[0] > 1)
			res = res.multiply(TWO.pow(a[0] - 1));*/
		for (int i = 1; i < m; i++)
			if (a[i] - a[i - 1] > 1)
				res = res.multiply(TWO.pow(a[i] - a[i - 1] - 2));
		/*if (n > a[m - 1])
			res = res.multiply(TWO.pow(n - a[m - 1] - 1));*/

		System.out.println(res.mod(BigInteger.valueOf(1000000007)));
	}

	static BigInteger fact(int n) {
		BigInteger res = BigInteger.ONE;
		for (int i = 2; i <= n; i++)
			res = res.multiply(BigInteger.valueOf(i));
		return res;
	}
}