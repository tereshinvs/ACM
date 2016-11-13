#include <stdio.h>

long long x[100000], y[100000];
long long square;
int n;

long long get_square(long long x1, long long y1, long long x2, long long y2) {
	return x1 * y2 - y1 * x2;
}

bool inside(long long tx, long long ty) {
	long long tsq = 0;
	for (int i = 1; i < n; i++) {
		long long temp = get_square(x[i] - tx, y[i] - ty, x[i - 1] - tx, y[i - 1] - ty);
		tsq += temp * (temp > 0 ? 1LL : -1LL);
		if (temp == 0)
			return false;
	}
	long long temp = get_square(x[0] - tx, y[0] - ty, x[n - 1] - tx, y[n - 1] - ty);
	tsq += temp * (temp > 0 ? 1LL : -1LL);
	if (temp == 0)
		return false;
	return tsq == square;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d%I64d", &x[i], &y[i]);
	for (int i = 1; i < n - 1; i++)
		square += get_square(x[i] - x[0], y[i] - y[0], x[i + 1] - x[0], y[i + 1] - y[0]);
	square *= square > 0 ? 1LL : -1LL;
	long long _x, _y; int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%I64d%I64d", &_x, &_y);
		if (!inside(_x, _y)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}