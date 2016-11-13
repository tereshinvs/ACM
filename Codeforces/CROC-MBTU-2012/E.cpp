#include <cstdio>
#include <cstring>

int _abs(int t) {
	return t > 0 ? t : -t;
}

int main() {
	char s[500];
	scanf("%s", s);
	int bal = 0, res_neg = 0, res_pos = 0;
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] == '+')
			bal++;
		else
			bal--;

		if (bal > 0) {
			if (bal > res_pos)
				res_pos = bal;
		}
		if (bal < 0) {
			if (-bal > res_neg)
				res_neg = -bal;
		}
	}
	printf("%d\n", res_pos + res_neg);
}