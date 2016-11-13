#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector< pair< int, int > > edge[500];
bool alr[500];

void dfs(int v, int left, int right) {
	alr[v] = true;
	for (int i = 0; i < edge[v].size(); i++)
		if ((edge[v][i].second < left || edge[v][i].second > right) &&
			!alr[edge[v][i].first])
			dfs(edge[v][i].first, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		edge[x].push_back(make_pair(y, i + 1));
		edge[y].push_back(make_pair(x, i + 1));
	}

	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int x, y;
		cin >> x >> y;

		for (int i = 0; i < n; i++)
			alr[i] = false;

		int res = 0;
		for (int i = 0; i < n; i++)
			if (!alr[i]) {
				res++;
				dfs(i, x, y);
			}
		cout << res << endl;
	}
}