#include <stdio.h>
#include <vector>

using namespace std;

vector< int > cl_cube[100000];
int alr[100000], n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x); x--;
		cl_cube[x].push_back(i - alr[x]);
		alr[x]++;
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		if (!cl_cube[i].size())
			continue;
		int l = 0;
		for (int j = 0; j < cl_cube[i].size(); j++) {
			while ((cl_cube[i][j] - cl_cube[i][l]) > k)
				l++;
			if (j - l + 1 > res)
				res = j - l + 1;
		}
	}
	printf("%d\n", res);
	return 0;
}