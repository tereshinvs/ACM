#include <cstdio>

using namespace std;

char shop[100][26];
char need[200];
int n, m;
int can[100];

int main() {
	scanf("%s", need);
	n = strlen(need);
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++) {
		char s[200];
		scanf("%s%d\n", s, can[i]);
		for (int j = 0; j < strlen(s); j++)
			shop[i][s[j] - 'a']++;
	}
	for (int i = 0; i < n; i++)
	return 0;
}