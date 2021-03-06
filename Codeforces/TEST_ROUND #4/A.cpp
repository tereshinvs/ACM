#include <stdio.h>

int main() {
	char c;
	bool is_word = true, was_w = false;
	while ((c = getchar()) != '\n') {
		if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z') {
			if (!is_word && was_w)
				printf(" ");
			printf("%c", c);
			is_word = true;
			was_w = true;
		} else if (c == ' ')
			is_word = false;
		else {
			printf("%c", c);
			is_word = false;
		}
	}
	return 0;
}