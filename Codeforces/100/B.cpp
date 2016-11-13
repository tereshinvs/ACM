#include <stdio.h>

int temp[301], temp1[301], temp2[301];
int info[301][301];
int al[301];
int n;

int get_max_p(int t, int non) {
	for (int i = 1; i <= n; i++)
		if (al[i] <= t && al[i] != non)
			return al[i];
	return -1;
}

int get_prior(int man, int t) {
	for (int i = 1; i <= n; i++)
		if (info[man][i] == t)
			return i;
}

int get_res(int t) {
	int gtemp = 0, minp = 1000000, minn = 0;
	for (int i = 1; i <= n; i++) {
		gtemp = get_max_p(i, t);
		if (gtemp == -1)
			continue;
		if (get_prior(t, gtemp) < minp) {
			minp = get_prior(t, gtemp);
			minn = i;
		}
	}
	return minn;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &info[i][j]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &al[i]);
		temp[i] = 0;
		temp1[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", get_res(i));
}