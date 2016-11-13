#include <stdio.h>
#include <iostream>

int get_num(char c) {
	switch (c) {
		case '>':
			return 8;
		case '<':
			return 9;
		case '+':
			return 10;
		case '-':
			return 11;
		case '.':
			return 12;
		case ',':
			return 13;
		case '[':
			return 14;
		case ']':
			return 15;
		default:
			return 0;
	}
}

int main() {
	unsigned long long res = 0;
	char c;
	while ((c = getchar()) != '\n')
		res = (res * 16 + get_num(c)) % 1000003;
	std::cout << res << std::endl;
	return 0;
}                       