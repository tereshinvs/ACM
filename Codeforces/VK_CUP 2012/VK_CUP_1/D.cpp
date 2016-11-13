#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> rb[50000];
bool alr[50000];
int res[50000][500];
unsigned long long ares = 0;

void dfs(int v) {
	alr[v] = true;
	for (int i = 0; i < rb[v].size(); i++)
		if (!alr[rb[v][i]])
			dfs(rb[v][i]);
	for (int i = 0; i < rb[v].size(); i++)
		for (int j = i + 1; j < rb[v].size(); j++) {
			if (alr[rb[v][i]] || alr[rb[v][j]])
				continue;
//			ares += res[rb[v][i]][k - 1] + res[rb[v][j]][k - 1];
			for (int q = 0; q < k - 1; q++)
				ares += res[rb[v][i]][q] * res[rb[v][j]][k - q - 2];
		}
	for (int i = 0; i < rb[v].size(); i++)
		ares += res[rb[v][i]][k - 1];
	res[v][0] = 1;
	for (int i = 0; i < rb[v].size(); i++)
		for (int j = 0; j < k; j++)
			res[v][j + 1] += res[rb[v][i]][j];
/*	printf("%d %d\n", v + 1, ares);
	for (int i = 0; i <= k; i++)
		printf("%d ", res[v][i]);
	printf("\n");*/
//	res[v][1] += rb[v].size();
	alr[v] = false;
}

int main() {
	scanf("%d%d\n", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		rb[x - 1].push_back(y - 1);
		rb[y - 1].push_back(x - 1);
	}
	for (int j = 0; j < n; j++) {
		alr[j] = false;
		for (int i = 0; i < k; i++)
			res[j][i] = 0;
	}
	dfs(0);
	cout << ares << endl;
	return 0;
}