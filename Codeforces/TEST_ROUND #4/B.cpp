#include <stdio.h>

#define INF 1000000000

int res[300][300], lng[300][300], n, m;

void floyd() {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (res[i][k] != -INF && res[k][j] != -INF && res[i][k] + res[k][j] > res[i][j]) {
					res[i][j] = res[i][k] + res[k][j];
					lng[i][j] = lng[i][k] + lng[k][j] - 1;
				}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			res[i][j] = res[j][i] = -INF;
			lng[i][j] = lng[j][i] = 301;
			if (i == j) {
				res[i][j] = 0;
				lng[i][j] = 1;
			}
		}
	int v1, v2, c1, c2;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &v1, &v2, &c1, &c2); v1--; v2--;
		res[v1][v2] = c1;
		res[v2][v1] = c2;
		lng[v1][v2] = lng[v2][v1] = 2;
	}
	floyd();
	int min_c = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (res[i][j] + res[j][i] > 0 && lng[i][j] + lng[j][i] - 2 < min_c)
				min_c = lng[i][j] + lng[j][i] - 2;
	printf("%d\n", min_c);
}