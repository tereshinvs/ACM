import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int one = 0, two = 0;
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			if (x == 50)
				one++;
			else
				two++;
		}

		int a[][] = new int[one + 1][two + 1];
		BigInteger res[][] = new BigInteger[one + 1][two + 1];
		boolean alr[][] = new boolean[one + 1][two + 1];

		for (int i1 = 0; i1 < one + 1; i1++)
			for (int j1 = 0; j1 < two + 1; j1++) {
				a[i1][j1] = 1000000000;
				res[i1][j1] = BigInteger.ZERO;
				alr[i1][j1] = false;
			}
		a[one][two] = 0;
		res[one][two] = BigInteger.ONE;

		for (int q = 0; q < (one + 1) * (two + 1); q++) {
			int t_x = -1, t_y = -1, t_min = 1000000001;
			for (int i = 0; i <= one; i++)
				for (int j = 0; j <= two; j++)
					if (!alr[i][j] && a[i][j] < t_min) {
						t_min = a[i][j];
						t_x = i;
						t_y = j;
					}
			alr[t_x][t_y] = true;
			for (int i1 = 0; i1 <= t_x; i1++)
				for (int j1 = 0; j1 <= t_y; j1++)
					for  (int i2 = 0; i2 <= one - t_x + i1; i2++)
						for (int j2 = 0; j2 <= two - t_y + j1; j2++) {
							if (50 * i1 + 100 * j1 > k || 50 * i2 + 100 * j2 > k || i1 == 0 && j1 == 0)
								continue;
							if ((i1 != t_x || j1 != t_y) && (i2 == 0 && j2 == 0))
								continue;
							int new_x = t_x - i1 + i2;
							int new_y = t_y - j1 + j2;
							int ret_val = 0;
							if (i2 > 0 || j2 > 0)
								ret_val = 1;
							if (a[t_x][t_y] + 1 + ret_val < a[new_x][new_y]) {
								a[new_x][new_y] = a[t_x][t_y] + 1 + ret_val;
								BigInteger mult = C(t_x, i1).multiply(C(t_y, j1));
								mult = mult.multiply(C(one - t_x + i1, i2)).multiply(C(two - t_y + j1, j2));
								res[new_x][new_y] = res[t_x][t_y].multiply(mult);
							} else if (a[t_x][t_y] + 1 + ret_val == a[new_x][new_y])
								res[new_x][new_y] = res[new_x][new_y].add(res[t_x][t_y]);
						}
		}

		if (a[0][0] < 1000000000) {
			System.out.println(a[0][0]);
			System.out.println(res[0][0]);
		} else {
			System.out.println(-1);
			System.out.println(0);			
		}
	}

	static BigInteger C(int n, int k) {
		return fact(n).divide(fact(k)).divide(fact(n - k));
	}

	static BigInteger fact(int n) {
		BigInteger res = BigInteger.valueOf(1);
		for (int i = 2; i <= n; i++)
			res = res.multiply(BigInteger.valueOf(i));
		return res;
	}
}