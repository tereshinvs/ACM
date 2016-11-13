#include <cstdio>
#include <cmath>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);
	int a[3 * n];
	for (int i = 0; i < 3 * n; i++)
		a[i] = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		if (a[i * 2 + 1] > 0 && i * 2 + 2 >= n) {
			printf("-1\n");
			return 0;
		}

	if (n == 1 && a[0] != 0) {
		printf("-1\n");
		return 0;
	}

	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i * 2 + 1 >= n)
			continue;
		if (a[i * 2 + 1] > 0 && i * 2 + 2 >= n) {
			printf("-1\n");
			return 0;
		}
		int temp = max(a[i * 2 + 1], a[i * 2 + 2]);
		a[i * 2 + 1] = 0;
		a[i * 2 + 2] = 0;
		res += temp;
		a[i] -= temp;
		if (a[i] < 0)
			a[i] = 0;
	}
	res += a[0];

	printf("%d\n", res);
	return 0;
}