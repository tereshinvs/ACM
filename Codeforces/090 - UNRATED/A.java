import java.util.Scanner;

public class A
	{
		public static void main(String[] args)
			{
				Scanner in = new Scanner(System.in);
				int a = in.nextInt(), b = in.nextInt(), n = in.nextInt(), temp, i;
				for (i = 0; n > 0; i++)
					if (i%2 == 0)
						{
							temp = gcd(a, n);
							if (temp > n)
								{
									System.out.println(1);
									System.exit(0);
								}
							n -= temp;
						} else {
							temp = gcd(b, n);
							if (temp > n)
								{
									System.out.println(0);
									System.exit(0);
								}
							n -= temp;
						}
				System.out.println(i%2 == 0 ? 1 : 0);
			}

		static int gcd(int t1, int t2)
			{
				return t2 == 0 ? t1 : gcd(t2, t1%t2);
			}
	}