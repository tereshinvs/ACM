#include <stdio.h>
#include <string.h>
#include <algorithm>

int max(int t1, int t2) {
	return t1 > t2 ? t1 : t2;
}

char s[40];

int get_number(int t1, int t2) {
	if (t2 - t1 + 1 > 7 || t2 < t1)
		return 10000000;
	int res = 0;
	if (t2 != t1 && s[t1] == '0')
		return 10000000;
	for (int i = t1; i <= t2; i++)
		res = res * 10 + s[i] - '0';
	return res;
}

int main() {
	scanf("%s", s);
	int res = -1;
	int lng = strlen(s);

	for (int i = 0; i < lng; i++)
		for (int j = i + 1; j < lng; j++) {
				int t1 = get_number(0, i);
				int t2 = get_number(i + 1, j);
				int t3 = get_number(j + 1, lng - 1);
				if (t1 <= 1000000 && t2 <= 1000000 && t3 <= 1000000)
					res = max(res, t1 + t2 + t3);
			}

	printf("%d\n", res);
	return 0;
}