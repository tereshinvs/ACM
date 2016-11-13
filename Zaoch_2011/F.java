import java.util.*;
import java.math.*;

public class Main
	{
		public static void main(String[] args)
			{
				Scanner in=new Scanner(System.in);
				long fn1, fn2, a[] = new long[20000002], l, r, med = 0, helpbi;
				int i, n1, n2, m, help;
				n1=in.nextInt()+1000000;
				n2=in.nextInt()+1000000;
				m=in.nextInt()+1000000;
				fn1=in.nextLong();
				fn2=in.nextLong();
				if (n1>n2) {
									help=n1;
									n1=n2;
									n2=help;
									helpbi=fn1;
									fn1=fn2;
									fn2=helpbi;
								}
				a[n1]=fn1;
				l=-2000000000; r=2000000000;
				while (true)
					{
						if (l > r) break;
//						System.out.println(l+" "+r);
						med=(l + r) / 2;
						a[n1+1]=med;
						for (i=n1+2; i<=n2; i++)
							a[i]=a[i-1] + a[i-2];
						if (a[n2] == fn2) break;
						if (a[n2] < fn2) l=med + 1;
						if (a[n2] > fn2) r=med - 1;
					}
				//System.out.println(med);
				for (i=n2+1; i<20000002; i++)
					a[i]=a[i-1] + a[i-2];
				for (i=n1-1; i>=0; i--)
					a[i]=a[i+2] - a[i+1];
/*				for (i=10000; i<=m; i++)
					System.out.println("* "+i+" "+a[i]);*/
				System.out.println(a[m]);
			}
	}