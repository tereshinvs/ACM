#include <stdio.h>
#include <iostream>

int pr[10000], k = 0;
long long tres[20000000];

long long max(long long t1, long long t2) {
	return t1 < t2 ? t2 : t1;
}

int main() {
	for (int i = 0; i < 20000000; i++)
		tres[i] = 0;

	for (int i = 2; i < 10000; i++) {
		bool flag = true;
		for (int j = 0; j < k && flag; j++)
			if (!(i % pr[j]))
				flag = false;
		if (flag)
			pr[k++] = i;
	}

	int a, n;
	scanf("%d%d", &a, &n);

	tres[1] = 1;
	for (int i = 1; i < a + n; i++) {
		for (int j = 0; j < k && i * pr[j] < a + n; j++)
			if (tres[i] % pr[j])
				tres[i * pr[j]] = max(tres[i] * pr[j], tres[i * pr[j]]);
			else
				tres[i * pr[j]] = max(tres[i] / pr[j], tres[i * pr[j]]);
		std::cout << i << " " << tres[i] << std::endl;
	}

	long long res = 0;
	for (int i = a; i < a + n; i++)
		res += tres[i];

	std::cout << res << std::endl;

	return 0;
}