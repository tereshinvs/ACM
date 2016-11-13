#include <cstdio>
#include <cstring>

using namespace std;

char c[1000000];

int main() {
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		int res = 0, respos = -1, lng = strlen(c), cur = 0;
		for (int j1 = 0, j2 = lng - 1; j1 < lng; j1++, j2--)
			if (c[j1] == c[j2])
				cur++;
			else {
				int temp = j1 - cur;
//				if (j2 < temp)
//					continue;
				if (cur > res) {
					res = cur;
					respos = temp;
				}
				cur = 0;
			}
		int temp = lng - cur;
		if (cur > res) {
			res = cur;
			respos = temp;
		}
		for (int i = respos; i < respos + res; i++)
			printf("%c", c[i]);
		printf("\n");
	}
	return 0;
}