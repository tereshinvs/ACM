#include <cstdio>

int a[100000], b[100000], n, p[100000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		p[a[i] - 1] = b[i];
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	return 0;
}