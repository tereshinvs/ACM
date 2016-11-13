import java.util.*;

public class E {
	static int mod = 1000000007;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), l = in.nextInt();
		int res[][] = new int[l + 1][n * 2];
		int a[][] = new int[n * 2][3], m = n;
		for (int i = 0; i < n; i++) {
			a[i][0] = in.nextInt();
			a[i][1] = in.nextInt();
			a[i][2] = i;
			if (a[i][0] != a[i][1]) {
				a[m][0] = a[i][1];
				a[m][2] = i;
				a[m++][1] = a[i][0];
			}
		}
//		n *= 2;
		for (int i = 0; i < m; i++)
			res[0][i] = 1;
		for (int i = 1; i <= l; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = 0;
				if (i - a[j][0] < 0)
					continue;
				if (i - a[j][0] == 0) {
					res[i][j] = 1;
					continue;
				}
				for (int q = 0; q < m; q++)
					if (a[j][2] != a[q][2] && a[j][0] == a[q][1]) {
						res[i][j] = (res[i][j] + res[i - a[j][0]][q]) % mod;
//						System.out.println("### " + j + " " + q);
					}
			}
//			for (int j = 0; j < m; j++)
//				System.out.print(res[i][j] + " ");
//			System.out.println();
		}
		int sum = 0;
		for (int i = 0; i < 2 * n; i++)
			sum = (sum + res[l][i]) % mod;
		System.out.println(sum);
	}
}