#include <stdio.h>
#include <algorithm>

int n, t[100], sum[100];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	std::sort(t, t + n);
	sum[0] = 10 + t[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + t[i];
	int res_p = 0, res_t = 0;
	for (int i = 0; i < n; i++)
		if (sum[i] <= 720) {
			res_p++;
			if (sum[i] > 360)
				res_t += sum[i] - 360;
		} else
			break;
	printf("%d %d\n", res_p, res_t);
}