#include <cstdio>
#include <stdlib.h>
#include <string.h>

using namespace std;

int s[26], n, tn;
char t[6000], curs[6000];

void brute_force(int lng, bool alr_g) {
	if (lng == tn && n > tn) {
		printf("%s", curs);
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < s[i]; j++)
				printf("%c", i + 'a');
		exit(0);
	}
	if (lng == n) {
		if (alr_g) {
			curs[lng] = 0;
			printf("%s\n", curs);
			exit(0);
		}
		return;
	}
	int ts = alr_g ? 0 : (t[lng] - 'a'), cur = 0;
	for (int i = ts; i < 26 && cur < 2; i++) {
		if (s[i]) {
			s[i]--;
			curs[lng] = i + 'a';
			brute_force(lng + 1, alr_g || (t[lng] < i + 'a'));
			s[i]++;
			cur++;
		}
	}
}

int main() {
	char c;
	while ((c = getchar()) != '\n') {
		s[c - 'a']++;
		n++;
	}
	scanf("%s", t); tn = strlen(t);
	brute_force(0, false);
	printf("-1\n");
	return 0;
}