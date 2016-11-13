#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char s[100001];
char t[100001];

int main() {
	gets(s);
	gets(t);
	int len1 = strlen(s), len2 = strlen(t), j = 0;
	sort(t, t + len2);
	for (int i = len2 - 1; i >= 0; i--) {
		while (j < len1 && s[j] >= t[i])
			j++;
		if (j == len1)
			break;
		s[j] = t[i];
	}
	printf("%s\n", s);
	return 0;
}