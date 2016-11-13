import java.util.Scanner;

public class B
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), a[] = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		int res = 0, min, max, t;
		for (int i = 0; i < (1 << n); i++)
		{
			min = 1000000000; max = 0; t = i;
			for (j = 0; j < n; j++)
			{
				temp = (t%i == 1 ? getMax(a[j]) : getMin(a[j]));
				if (temp < min)
					min = temp;
				if (temp > max)
					max = temp;
			}
			if (max - min > res)
				res = max - min;
		}
	}

	static int getMax(int t)
	{
	}
}