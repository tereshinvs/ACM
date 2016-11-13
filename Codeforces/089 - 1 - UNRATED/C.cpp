#include <stdio.h>
//#include <math.h>

int change[10];
char s[10000];
int val[10], n, k;

int abs(int t)
	{
		return t>0 ? t : -t;
	}

int min(int t1, int t2)
	{
		return t1<t2 ? t1 : t2;
	}

int get_change(int i)
	{
				for (int j = 0; j < 10; j++)
					change[j] = 0;
				int alr = 0, res = 0;
				for (int j = 0; j <= 9; j++)
					{
						if (i+j <= 9)
						if (val[i+j] >= k - alr)
							{
								change[i+j] = k - alr;
								res += change[i+j]*j;
								break;
							} else {
								alr += val[i+j];
								change[i+j] = val[i+j];
								res += change[i+j]*j;
							}
						if (j == 0) continue;
						if (i-j>=0)
						if (val[i-j] >= k - alr)
							{
								change[i-j] = k - alr;
								res += change[i-j]*j;
								break;
							} else {
								alr += val[i-j];
								change[i-j] = val[i-j];
								res += change[i-j]*j;
							}
					}
				return res;
	}

void output(int t, int res)
	{
//		int res = 0;
		for (int i = 0; i < n; i++)
			if (s[i] - '0' > t && change[s[i] - '0'] > 0)
				{
//					res += abs(s[i] - '0' - t);
					change[s[i] - '0']--;
					s[i] = t + '0';
				}
		for (int i = n - 1; i >= 0; i--)
			if (s[i] - '0' < t && change[s[i] - '0'] > 0)
				{
//					res += abs(s[i] - '0' - t);
					change[s[i] - '0']--;
					s[i] = t + '0';
				}
		printf("%d\n%s\n", res, s);
	}

int main()
	{
		for (int i = 0; i < 10; i++)
			val[i] = 0;
		scanf("%d%d", &n, &k);
		while (getchar() != '\n');
		scanf("%s", &s);
		for (int i = 0; i < n; i++)
			val[s[i] - '0']++;
//		for (int i = 0; i < 10; i++)
//			printf("%d = %d\n", i, val[i]);
		int res = 1000000000, temp, res_i;
		for (int i = 0; i < 10; i++)
			{
				temp = get_change(i);
//				printf("%d - %d\n", i, temp);
				if (temp < res) res = temp, res_i = i;
			}
		get_change(res_i);
//		printf("%d\n", res_i);
		output(res_i, res);
		return 0;
	}