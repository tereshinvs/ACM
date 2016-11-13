#include <stdio.h>
#include <cstring>

using namespace std;

int main() {
	int x = 0, y = 0;
	char c;
	while ((c = getchar()) != '\n')
		if (c == 'x')
			x++;
		else
			y++;
	if (x > y)
		for (int i = 0; i < x - y; i++)
			printf("x");
	else
		for (int i = 0; i < y - x; i++)
			printf("y");
	printf("\n");
	return 0;
}