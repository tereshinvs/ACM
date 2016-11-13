#include <cstdio>

using namespace std;

int res[100];

void do_magic(int t1, int t2, int a) {
	for (int i = 0; i < 32; i++, a /= 2)
		if (a % 2 == 1) {
			res[t1] |= 1 << i;
			res[t2] |= 1 << i;
		}
}

int main() {
	int n;
	scanf("%d", &n);
	int a[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			do_magic(i, j, a[i][j]);

	for (int i = 0; i < n; i++)
		printf("%d ", res[i]);
}