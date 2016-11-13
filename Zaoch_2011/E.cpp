#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b, res[1000], max_len;
vector< pair<int, int> > edge[1000];
priority_queue< pair<int, int> > q;
bool alr[1000];

int dfs(int cur) {
	if (cur == b)
		return 1;
	alr[cur] = true;
	int dres = 0;
	for (int i = 0; i < edge[cur].size(); i++)
		if (!alr[edge[cur][i].first] && res[edge[cur][i].first] == res[cur] + edge[cur][i].second)
			dres += dfs(edge[cur][i].first);
	alr[cur] = false;
	return dres;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v1, v2, mass;
		scanf("%d%d%d", &v1, &v2, &mass); v1--; v2--;
		edge[v1].push_back(make_pair(v2, mass));
		edge[v2].push_back(make_pair(v1, mass));
	}
	scanf("%d%d", &a, &b); a--; b--;
	for (int i = 0; i < n; i++) {
		res[i] = i == a ? 0 : 1000000000;
		alr[i] = false;
		q.push(make_pair(-res[i], i));
	}
	for (int t = 0; t < n; t++) {
		while (alr[q.top().second])
			q.pop();
		int cur = q.top().second; q.pop(); alr[cur] = true;
		for (int i = 0; i < edge[cur].size(); i++)
			if (res[edge[cur][i].first] > res[cur] + edge[cur][i].second)
				res[edge[cur][i].first] = res[cur] + edge[cur][i].second;
	}
	for (int i = 0; i < n; i++)
		alr[i] = false;
	if (res[b] == 1000000000) {
		printf("0\n");
		return 0;\
	}
	max_len = res[b];
	printf("%d\n", dfs(a, 0));
}