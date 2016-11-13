#include <set>
#include <cstdio>
#include <map>

using namespace std;

map<int, int> res[4000];
int a[4000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (res[j][a[i]] > 0)
				res[i][a[j]] = res[j][a[i]] + 1;
			else
				res[i][a[j]] = 2;
	int res_max = 1;
	for (int i = 0; i < n; i++)
		for (map<int, int>::iterator it = res[i].begin(); it != res[i].end(); it++)
			if (it->second > res_max)
				res_max = it->second;
	printf("%d\n", res_max);
	return 0;
}