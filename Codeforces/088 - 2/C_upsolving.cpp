#include <stdio.h>

using namespace std;

char table[5000][5000];
bool alr[5000], cycle = false;
int cycle_list[5000], vert_prev[5000], k = 0, prev[5000], next[5000], first_vert, n, colour[5000];

void get_cycle(int st, int fn)
	{
//		printf("st = %d  fn = %d\n", st, fn);
		for (int i = fn; i != st; i = vert_prev[i])
			cycle_list[k++] = i;
		cycle_list[k++] = st;
		cycle = true;
	}

void dfs(int v, int last)
	{
		colour[v] = 1;
		vert_prev[v] = last;
		for (int i = 0; i < n; i++)
			{
				if (cycle) break;
				if (i == v || i == last) continue;
				if (table[v][i] == '1')
					if (colour[i] == 1)
						{
							get_cycle(i, v);
							cycle = true;
						}
					else if (colour[i] == 0) dfs(i, v);
			}
		colour[v] = 2;
	}

int main()
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			{
				while (getchar() != '\n');
				for (int j = 0; j < n; j++)
					table[i][j] = getchar();
				colour[i] = 0;
			}
		for (int i = 0; i < n; i++)
			{
				dfs(i, -1);
				if (cycle) break;
			}
		if (!cycle)
			{
				printf("-1\n");
				return 0;
			}

//		printf("aaa\n");
//		for (int i = 0; i < k; i++)
//			printf("%d\n", cycle_list[i]);
		for (int i = 0; i < k; i++)
			{
				prev[i] = i - 1;
				next[i] = i + 1;
			}
		prev[0] = k - 1;
		next[k - 1] = 0;
		first_vert = 0;
		while (k >= 3)
			if (table[ cycle_list[prev[first_vert]] ][ cycle_list[next[first_vert]] ] == '1')
				{
					printf("%d %d %d\n", cycle_list[prev[first_vert]]+1, cycle_list[next[first_vert]]+1, cycle_list[first_vert]+1);
					return 0;
				}
			else {
					next[prev[first_vert]] = next[first_vert];
					first_vert = prev[first_vert];
					k--;
				}
		return 0;
	}