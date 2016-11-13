import java.util.Scanner;

public class D
	{
		public static void main(String[] args)
			{
				Scanner in = new Scanner(System.in);
				int n1 = in.nextInt(), n2 = in.nextInt(), k1 = in.nextInt(), k2 = in.nextInt();
				int res[][][] = new int[n1 + n2][n1+1][1 << 9]; // 1 - k1; 0 -k2
				res[0][0][0] = 1;
				res[0][1][1] = 1;
				for (int i = 1; i < n1+n2; i++)
					for (int j = 0; j <= n1; j++)
						{
							if (j < n1)
								for (int q = 0; q <= n1; q++)
									if ((~q)%(1 << (k1+1)) != 0)
										res[i][j][1] += res[
						}
			}
	}