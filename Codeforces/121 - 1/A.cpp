#include <cstdio>
#include <cstring>

using namespace std;

/*int a[600000][26], n;
char st[500000], en[500000];*/
int a[26][26], n;
char s[20];

int max(int t1, int t2) {
	return t1 > t2 ? t1 : t2;
}

int main() {
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			a[i][j] = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int lng = strlen(s);
		char st = s[0] - 'a', en = s[lng - 1] - 'a';
//		a[st][en] = max(a[st][en], lng);
		for (int j = 0; j < 26; j++)
			if (a[j][st] != 0 || j == st)
				a[j][en] = max(a[j][en], a[j][st] + lng);
	}
/*	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}*/
	int res = 0;
	for (int i = 0; i < 26; i++)
		res = max(res, a[i][i]);
	printf("%d\n", res);
	return 0;
}