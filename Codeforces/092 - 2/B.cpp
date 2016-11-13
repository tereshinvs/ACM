#include <algorithm>
#include <stdio.h>

using namespace std;

int perm[8], n, k;
char a[10][10];

int gperm(int t)
{
	int res = 0;
	for (int i = 0; i < k; i++)
		res = res*10 + a[t][perm[i]] - '0';
	return res;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		while (getchar()!='\n');
		for (int j = 0; j < k; j++)
			scanf("%c", &a[i][j]);
	}
	for (int i = 0; i < k; i++)
		perm[i] = i;
	int mn, mx, res = 1000000000, temp;
	do
	{
		mn = 1000000000; mx = 0;
		for (int i = 0; i < n; i++)
		{
			temp = gperm(i);
			if (temp < mn)
				mn = temp;
			if (temp > mx)
				mx = temp;
		}
		if (mx - mn < res)
			res = mx - mn;
	} while (next_permutation(perm, perm + k));
	printf("%d\n", res);
	return 0;
}