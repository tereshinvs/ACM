#include <stdio.h>
#include <string.h>

char s[1001], res[1001];
int mat[1001][1001], n, vl[26], alr[1000], ralr[1000];

int gcd(int t1, int t2)
{
	return t1 == 0 ? t2 : gcd(t2%t1, t1);
}

int dfs(int v)
{
//	printf("gcd %d\n", v);
	alr[v] = 1;
	int dres = 0;
	for (int i = 0; i < n; i++)
		if (mat[v][i] && !alr[i])
			dres+=dfs(i);
	return dres + 1;
}

void rdfs(int v, char c)
{
	ralr[v] = 1;
	res[v] = c;
	for (int i = 0; i < n; i++)
		if (mat[v][i] && !ralr[i])
			rdfs(i, c);
}

char gtc(int t)
{
	int mn = 100000000, mni;
	for (int i = 0; i < 26; i++)
		if (vl[i] >= t && vl[i] < mn)
		{
			mn = vl[i];
			mni = i;
		}
	if (mn == 100000000)
		return 0;
	vl[mni] -= t;
	return mni + 'a';
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			mat[i][j] = (mat[j][i] = (gcd(i+1, j+1) > 1));
	for (int i = 0; i < n; i++)
	{
		alr[i] = 0;
		ralr[i] = 0;
	}
	for (int i = 0; i < 26; i++)
		vl[i] = 0;
	for (int i = 0; i < n; i++)
		vl[s[i]-'a']++;
	int temp; char c;
	for (int i = 0; i < n; i++)
	{
		if (alr[i]) continue;
		temp = dfs(i);
		c = gtc(temp);
//		printf("!%d %d %c\n", i, temp, c);
		if (!c)
		{
			printf("NO\n");
			return 0;
		}
		rdfs(i, c);
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%c", res[i]);
	return 0;
}