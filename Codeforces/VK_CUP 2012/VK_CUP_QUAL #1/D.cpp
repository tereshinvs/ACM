#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	int res = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		res += a[i];
	}
	for (int i = 3; i < n; i++) {
		if (n % i)
			continue;
		for (int j = 0; j < n / i; j++) {
			int _res = 0;
			for (int q = j; q < n; q += n / i)
				_res += a[q];
			if (_res > res)
				res = _res;
		}
	}
	printf("%d\n", res);
	return 0;
}