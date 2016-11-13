#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[100001];

int main() {
	int n, k, l, r;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	l = (int)(lower_bound(a, a + n, k) - a);
	r = (int)(upper_bound(a, a + n, k) - a - 1);
	int res = 0;
	if (a[l] == k) {
lbl:	int med = (n + 1) / 2 - 1;
		if (l <= med && med <= r) {
			printf("%d\n", res);
			return 0;
		}// r - l + l + res +1 = n - r - 1
		// res = n - r - 1 - r - 1
		if (l < n - r - 1) {
			res += n - 2 * r - 2;
			printf("%d\n", res);
			return 0;
		}
		// l = r - l + (n - r - 1) + res
		// res = 2 * l - n + 1
		if (n - r - 1 < l) {
			res += 2 * l - n + 1;
			printf("%d\n", res);
			return 0;
		}
	} else {
		a[n++] = k;
		sort(a, a + n);
		l = (int)(lower_bound(a, a + n, k) - a);
		r = (int)(upper_bound(a, a + n, k) - a - 1);
		res = 1;
		goto lbl;
	}
	return 0;
}