import java.util.Scanner;

public class B
	{
		public static void main(String[] args)
			{
				int n = new Scanner(System.in).nextInt();
				for (int i = 0; i < n; i++)
					{
						System.out.print(" ");
						for (int j = 1; j < n - i; j++)
							System.out.print("  ");
						for (int j = 0; j <= i; j++)
							System.out.print(" " + j);
						for (int j = i - 1; j >= 0; j--)
							System.out.print(" " + j);
						System.out.println();
					}
				System.out.print(0);
				for (int i = 1; i <= n; i++)
					System.out.print(" "+i);
				for (int i = n -1; i >= 0; i--)
					System.out.print(" "+i);
				System.out.println();
				for (int i = n-1; i >= 0; i--)
					{
						System.out.print(" ");
						for (int j = 1; j < n - i; j++)
							System.out.print("  ");
						for (int j = 0; j <= i; j++)
							System.out.print(" " + j);
						for (int j = i - 1; j >= 0; j--)
							System.out.print(" " + j);
						System.out.println();
					}
			}
	}