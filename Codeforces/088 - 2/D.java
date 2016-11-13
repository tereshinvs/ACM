import java.io.*;

public class D
	{
		static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

		static long readLong() throws IOException
			{
				in.nextToken();
				return (long)in.nval;
			}

		public static void main(String[] args) throws IOException
			{
				long n = readLong(), l, r, u, v, neven = n/2, nodd = (n%2 == 0 ? n/2 : (n/2+1)), res, u1 = 0, v1 = 0;
				System.out.println("even = " + neven + " odd = " + nodd);
				int m = (int)readLong(), mod = (int)readLong();
				for (int q = 0; q < m; q++)
					{
						l = readLong(); r = readLong(); u = readLong(); v = readLong();
						if (r <= nodd)
							{
								if (u%2 == 0) u++;
								if (v%2 == 0) v--;
								if (l*2-1 > u) u1 = l*2-1; else u1 = u;
								if (r*2-1 < v) v1 = r*2-1; else v1 = v;
								u = Math.max(u1, u); v = Math.min(v1, v);
								if (u > v) { System.out.println(0); continue; }
								System.out.println(((u%mod + v%mod)%mod)*((r-l+1)%mod)/2);
								continue;
							}
						if (l > nodd)
							{
								if (u%2 == 1) u++;
								if (v%2 == 1) v--;
								if ((l - nodd)*2 > u) u1 = (l-nodd)*2; else u1 = u;
								if ((r - nodd)*2 < v) v1 = (r-nodd)*2; else v1 = v;
								u = Math.max(u1, u); v = Math.min(v1, v);
								if (u > v) { System.out.println(0); continue; }
								System.out.println(((u%mod + v%mod)%mod)*((r-l+1)%mod)/2);
								continue;
							}
						if (u%2 == 0) u++;
						if (l*2-1 > u) u1 = l*2-1; else u1 = u;
						vt = v;
						if (vt
						u = Math.max(u, u1);
						if (u > nodd*2-1) { System.out.println(0); continue; }
						res = ((u%mod + (nodd*2-1)%mod)%mod)*((r-l+1)%mod)/2;
		
						if (v%2 == 1) v--;
						if (l*2 < v) v1 = l*2; else v1 = v;
						v = Math.max(v, v1);
						if (v <= 2) { System.out.println(0); continue; }
						res += ((2%mod + v%mod)%mod)*((r-l+1)%mod)/2;
						System.out.println(res);
					}
			}
	}