#include <stdio.h>

int main() {
	char c;
	bool flag = false;
	while ((c = getchar()) != '\n')
		if (c == 'H' || c == 'Q' || c == '9')
			flag = true;
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}