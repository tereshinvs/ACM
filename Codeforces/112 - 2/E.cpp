#include <stdio.h>

int alr[4000001], n, a[1000000], res[4000001];

int prb(int ost, int cur, int pos) {
/*	if (!ost) {
		if (alr[cur])
			return cur;
		else
			return -1;
	}*/
	if (alr[cur])
		return cur;
	if (pos > 20)
		return -1;
	if (ost % 2)
		return prb(ost / 2, cur, pos + 1);
	else {
		int prb1 = prb(ost / 2, cur, pos + 1);
		cur += 1 << pos;
		int prb2 = prb(ost / 2, cur, pos + 1);
		if (prb1 != -1)
			return prb1;
		else
			return prb2;
	}
}

int get_num(int t) {
	if (res[t] != -2)
		return res[t];
	res[t] = prb(t, 0, 0);
	return res[t];
}

int main() {
	for (int i = 0; i <= 4000000; i++) {
		alr[i] = 0;
		res[i] = -2;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		alr[a[i]] = 1;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", get_num(a[i]));
	return 0;
}