#include <stdio.h>

int main() {
	printf("50000 500\n");
	for (int i = 0; i < 49999; i++)
		printf("%d %d\n", i + 1, i + 2);
	return 0;
}