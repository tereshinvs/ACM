#include <iostream>

using namespace std;

int n1, n2, k1, k2;
int res[201][101][1024];

int min(int t1, int t2)
	{
		return t1<t2 ? t1 : t2;
	}

int main()
	{
		cin >> n1 >> n2 >> k1 >> k2;
		for (int i = 0; i < n1+n2+1; i++)
			for (int j = 0; j <= n1; j++)
				for (int q = 0; q < 1024; q++)
					res[i][j][q] = 0;
//		for (int i = 0; i <= n1; i++)
//			res[0][0][i] = 1;
		if (n2 > 1 || n1 > k1) res[1][0][1022] = 1;
		if (n1 > 1 || n2 > k2) res[1][1][1] = 1;
		for (int i = 0; i < n1+n2; i++)
			for (int j = 0; j <= min(n1, i); j++)
				for (int q = 0; q < 1024; q++)
					{
//						if (!(q << 1)%(1 << k2) || !((q << 1)+1)%(1 << k1)) continue;
						if ((q << 1)%(1 << k2) && i - j < n2)
							res[i+1][j][(q << 1)%1023] += res[i][j][q];
						if (((q << 1)+1)%(1 << k1) && j < n1)
							res[i+1][j+1][((q << 1)+1)%1023] += res[i][j][q];
/*						if (q%(1 << k2) == 0 || ((q+1)%(1 << k1) == 0)) continue;
//						if ((n1+n2-i)-(n1-j) < n2) continue;
						if (j > n1) continue;
						if (i - j > n2) continue;
						for (int w = 0; w < 1024; w++)
							{
								if (q >> 1 != ((w << 1) >> 1)) continue;
								res[i][j][q] = (res[i][j][q] + res[i-1][j - (q%2 ? 1 : 0)][w])%100000000;
							}*/
					}
		int sum = 0;
		for (int q = 0; q < 1024; q++)
			{
				if (q%(1 << k2) == 0 || ((q+1)%(1 << k1)) == 0) continue;
				sum = (sum + res[n1+n2][n1][q])%100000000;
			}
		cout << sum << endl;
		return 0;
	}