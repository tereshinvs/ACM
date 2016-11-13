#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool ftp(char *s) {
	return s[0] == 'f' && s[1] == 't' && s[2] == 'p';
}

int main() {
	char s1[100];
	char *s = s1;
	scanf("%s", s1);
	if (ftp(s)) {
		printf("ftp://");
		s += 3;
	} else {
		printf("http://");
		s += 4;
	}
	char *ru = strstr(s, "ru");
	if (ru == s) {
		printf("ru");
		s += 2;
		ru = strstr(s, "ru");
	}
	for (; s < ru; s++)
		printf("%c", *s);
	printf(".ru");
	ru += 2;
	if (*ru == 0) {
		printf("\n");
		return 0;
	}
	printf("/%s\n", ru);
	return 0;
}