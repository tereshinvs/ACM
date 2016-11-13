#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[] = {0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x - 1]++;
	}
	int res = a[3] + a[2];
	a[0] = a[0] < a[2] ? 0 : (a[0] - a[2]);
	int temp = 2 * a[1] + a[0];
	res += temp / 4 + (temp % 4 > 0);
	printf("%d\n", res);
	return 0;
}