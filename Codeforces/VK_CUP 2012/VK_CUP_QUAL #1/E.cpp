#include <stdio.h>
#include <algorithm>

struct call {
	int st, lng;
};

int n, k;
call a[4000];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].st, &a[i].lng);
	int res = 0;
	for (int i = 75000; i <= 75000; i++) {
		int tk = k, curtime = 1, first_st = 86401;
		for (int j = 0; j < n; j++) {
			printf("j=%d curtime=%d tk=%d\n", j, curtime, tk);
			int tstart = std::max(curtime, a[j].st);
			if (tstart > 86401)
				break;
			if (tstart + a[j].lng <= i) {
				curtime = tstart + a[j].lng;
				continue;
			}
			if (!tk) {
				first_st = tstart;
				break;
			}
			tk--;
		}
		if (first_st - i > res) {
			res = first_st - i;
			printf("%d %d\n", i, first_st);
		}
	}
	printf("%d\n", res);
	return 0;
}