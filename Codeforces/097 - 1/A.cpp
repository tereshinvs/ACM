#include <stdio.h>
#include <algorithm>

using namespace std;

int a[100000];

int only_ones(int n) {
	for (int i = 0; i < n; i++)
		if (a[i] != 1)
			return 0;
	return 1; 
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (only_ones(n)) {
		for (int i = 0; i < n - 1; i++)
			printf("1 ");
		printf("2\n");
		return 0;
	}
	sort(a, a + n);
	printf("%d ", 1);
	for (int i = 1; i < n; i++)
 			printf("%d ", a[i - 1]);
	return 0;
}