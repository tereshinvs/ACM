#include <stdio.h>

using namespace std;

char s1[100001], s2[100001];
int a[100000][26], b[100000];

int main() {
	scanf("%s", s1); scanf("%s", s2);
	int n1 = strlen(s1), n2 = strlen(s2);
	if (s1[0] == '?')
		b[0] = 1;
	else
		a[0][s1[0] - 'a'] = 1;
	for (int i = 1; i < n1; i++) {
		for (int j = 0; j < 26; j++)
			a[i][j] = a[i - 1][j];
		b[i] = b[i - 1];
		if (s1[i] == '?')
			b[i]++;
		else
			a[i][s1[i] - 'a']++;
	}
	for (int i =
}