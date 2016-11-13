#include <stdio.h>        	
#include <algorithm>

using namespace std;

struct tov {
	int c, t, num;
};

tov a[1000];
int n, k;
int put[1000][1000], _put[1000];

bool cmp(tov t1, tov t2) {
	if (t1.c > t2.c)
		return true;
	if (t1.c < t2.c)
		return false;
	return t1.t > t2.c;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].c, &a[i].t);
		a[i].num = i + 1;
	}
	sort(a, a + n, cmp);
	double res = 0;
	int alr = 0;
	for (int i = 0; i < n;) {
		int last = i;
		while (a[i].t != 1 && n - i - 1 >= k - alr) {
			if (k >= alr + 1 && i == n - 2)
				break;
			i++;
		}
		if (a[i].t == 1) {
			_put[alr] = 0;
			for (int j = last; j < i; j++) {
				res += a[j].c;
				put[alr][_put[alr]++] = a[j].num;
			}
			res += a[i].c / 2.0;
			put[alr][_put[alr]++] = a[i].num;
		} else {
			for (int j = last; j <= i; j++) {
				res += a[j].c;
				put[alr][_put[alr]++] = a[j].num;
			}
		}
		alr++;
		i++;
	}
	printf("%.1Lf\n", res);
	for (int i = 0; i < k; i++) {
		printf("%d ", _put[i]);
		for (int j = 0; j < _put[i]; j++)
			printf("%d ", put[i][j]);
		printf("\n");
	}
	return 0;
}