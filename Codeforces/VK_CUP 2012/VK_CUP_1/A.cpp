#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, x, y, k = 0;
int need[100000], have[100000];
pair<int, int> res[100000];

int main() {
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i < n; i++)
		scanf("%d", &need[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &have[i]);
	for (int i = 0, j = 0; i < n && j < m; i++) {
		while (j < m && have[j] < need[i] - x)
			j++;
		if (j == m)
			break;
		if (need[i] + y >= have[j]) {
			res[k++] = make_pair(i + 1, j + 1);
			j++;
		}
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}