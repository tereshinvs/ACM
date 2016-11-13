import java.io.*;
import java.util.*;

public class B
	{
		static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

		static int readInt() throws IOException
			{
				in.nextToken();
				return (int)in.nval;
			}

		public static void main(String[] args) throws IOException
			{
				int n = readInt(), k = readInt(), a[] = new int[n], q, sum, x;
				double min = 1000000000, max = 0.0;
				boolean alr[] = new boolean[n];
				for (int i = 0; i < n; i++)
					{
						a[i] = readInt();
						alr[i] = false;
					}
				q = readInt();
				for (int i = 0; i < q; i++)
					{
						sum = 0;
						for (int j = 0; j < n/k; j++)
							{
								x = readInt() - 1;
								sum += a[x];
								alr[x] = true;
							}
						if (sum/(n/k + 0.0) < min)
							min = sum/(n/k + 0.0);
						if (sum/(n/k + 0.0) > max)
							max = sum/(n/k + 0.0);
					}
//				System.out.println(min + " " + max);

				int nalr[] = new int[n], t = 0;
				for (int i = 0; i < n; i++)
					if (!alr[i])
						nalr[t++] = a[i];
				Arrays.sort(nalr, 0, t);

//				System.out.println("t = " + t);
				if (n/k <= t && (n-t)/(n/k) < k) {
				sum = 0;
				for (int i = 0; i < n/k; i++)
					sum += nalr[i];
				if (sum/(n/k + 0.0) < min)
					min = sum/(n/k + 0.0);
				if (sum/(n/k + 0.0) > max)
					max = sum/(n/k + 0.0);

//				System.out.println(min + " " + max);

				sum = 0;
				for (int i = t - 1; i > t - n/k - 1; i--)
					sum += nalr[i];
				if (sum/(n/k + 0.0) < min)
					min = sum/(n/k + 0.0);
				if (sum/(n/k + 0.0) > max)
					max = sum/(n/k + 0.0); }
				System.out.println(min + " " + max);
			}
	}