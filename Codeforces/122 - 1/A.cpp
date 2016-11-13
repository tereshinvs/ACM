#include <cstdio>

using namespace std;

char c[50][50];
bool alr[50][50];
int n, m;

void dfs(int vx, int vy) {
	alr[vx][vy] = true;
	if (vx && c[vx - 1][vy] == '#' && !alr[vx - 1][vy])
		dfs(vx - 1, vy);
	if (vx < n - 1 && c[vx + 1][vy] == '#' && !alr[vx + 1][vy])
		dfs(vx + 1, vy);
	if (vy && c[vx][vy - 1] == '#' && !alr[vx][vy - 1])
		dfs(vx, vy - 1);
	if (vy < m - 1 && c[vx][vy + 1] == '#' && !alr[vx][vy + 1])
		dfs(vx, vy + 1);
}

int main() {
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			c[i][j] = getchar();
		getchar();
	}
	bool flag = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '.')
				continue;
			flag = true;
			c[i][j] = '.';
			int lx = -1, ly = -1;
			for (lx = 0; lx < n; lx++)
				for (ly = 0; ly < m; ly++)
					if (c[lx][ly] == '#')
						goto gt;
			printf("-1\n");
			return 0;
gt:
			for (int i1 = 0; i1 < n; i1++)
				for (int j1 = 0; j1 < m; j1++)
					alr[i1][j1] = false;
			dfs(lx, ly);
//			bool flag = false;
			for (int i1 = 0; i1 < n; i1++)
				for (int j1 = 0; j1 < m; j1++)
					if (c[i1][j1] == '#' && !alr[i1][j1]) {
						printf("1\n");
						return 0;
					}
			c[i][j] = '#';
		}
	if (flag)
		printf("2\n");
	else
		printf("-1\n");
}