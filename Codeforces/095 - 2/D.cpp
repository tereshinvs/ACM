#include <stdio.h>
#include <stdlib.h>

int alr[3000], res[3000], mat[3000][3000], q[3000], n;

void cycle_found(int st, int fn, int dep) {
	int pos, cur, curres;
	for (int i = 0; i < dep; i++)
		if (q[i] == st) {
			pos = i;
			break;
		}
	for (int i = 0; i < n; i++)
		alr[i] = 0;
	for (;; pos++) {
		res[q[pos]] = 0;
		alr[q[pos]] = 0;
		if (q[pos] == fn)
			break;
	}
	for (int i = 0; i < n; i++) {
		cur = -1; curres = 1000000000;
		for (int j = 0; j < n; j++)
			if (!alr[j] && res[j] < curres) {
				curres = res[j];
				cur = j;
			}
		alr[cur] = 1;
		for (int j = 0; j < n; j++)
			if (mat[cur][j] && res[cur] + 1 < res[j])
				res[j] = res[cur] + 1;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", res[i]);
	exit(0);
}

void dfs(int v, int last, int dep) {
	if (alr[v])
		cycle_found(v, last, dep - 1);
	alr[v] = 1;
	q[dep] = v;
	for (int i = 0; i < n; i++)
		if (mat[v][i] && i != last)
			dfs(i, v, dep + 1);
}

int main() {
	int i, j, x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			mat[i][j] = 0;
		alr[i] = 0;
		res[i] = 100000000;
		q[i] = 0;
	}
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x, &y); x--; y--;
		mat[x][y] = 1;
		mat[y][x] = 1;
		q[x]++; q[y]++;
	}
	dfs(0, -1, 0);
	return 0;
}