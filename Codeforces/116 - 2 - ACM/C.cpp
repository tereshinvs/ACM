#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

char s[1000001];
int res[1000001][2];

int min(int t1, int t2) {
	return t1 < t2 ? t1 : t2;
}

int main() {
	scanf("%s", s);
	if ('A' <= s[0] && s[0] <= 'Z')
		res[0][1] = 1;
	else
		res[0][0] = 1;
	int n = strlen(s);
	for (int i = 1; i < n; i++)
		if ('A' <= s[i] && s[i] <= 'Z') {
			res[i][0] = res[i - 1][0];
			res[i][1] = min(res[i - 1][0], res[i - 1][1]) + 1;
		} else {
			res[i][0] = res[i - 1][0] + 1;
			res[i][1] = min(res[i - 1][0], res[i - 1][1]);
		}
	printf("%d\n", min(res[n - 1][0], res[n - 1][1]));
	return 0;
}