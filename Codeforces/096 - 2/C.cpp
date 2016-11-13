#include <stdio.h>

unsigned char rev(unsigned char t) {
	unsigned char res = 0;
	for (int i = 0; i < 8; i++, t >>= 1)
		res = res * 2 + t % 2;
	return res;
}

int main() {
	unsigned char last = 0, c, temp;
	while ((c = getchar()) != '\n') {
		temp = rev(last);
		for (int i = 0; i < 256; i++)
			if (rev(temp - i) == c) {
				printf("%d\n", i);
				break;
			}
		last = c;
	}
	return 0;
}