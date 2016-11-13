#include <stdio.h>

int main() {
	char s[100];
	int len = 0;
	while ((c = getchar()) != '\n')
		if (len && s[len - 1] == c && c == 'T')
			len--;
		else
			s[len++] = c;
	int a;
	scanf("%d", a);
	int temp = 0;
	for (int i = 0; i < len; i++)
		temp += s[i] == 'T';
	if (temp <= a) {
		int last = 
	}
	return 0;
}