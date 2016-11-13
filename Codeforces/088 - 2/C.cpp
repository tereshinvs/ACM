#include <stdio.h>

using namespace std;

char table[5000][5000];
int depth[5000], prev[5000], res, n;
bool alr[5000], result = false;

void dfs(int v, int dep, int last)
	{
		alr[v] = true;
		depth[v] = dep;
		prev[v] = last;
		for (int i = 0; i < n; i++)
			{
				if (result) return;
				if (table[v][i] == '1')
					{
						if (depth[v]-depth[i] == 2)
							{
								result = true;
								res = v;
							}
						else if (!alr[i]) dfs(i, dep+1, v);
					}
			}
		depth[v] = -1000;
	}

int main()
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			{
				while (getchar() != '\n');
				for (int j = 0; j < n; j++)
					table[i][j] = getchar();
				alr[i] = false;
			}
		for (int i = 0; i < n; i++)
			if (!alr[i])
				{
					for (int j = 0; j < n; j++)
						depth[j] = -1000;
					dfs(i, 0, -1);
					if (result)
						{
							printf("%d %d %d\n", prev[prev[res]]+1, prev[res]+1, res+1);
							return 0;
						}
				}
		printf("-1\n");
		return 0;
	}