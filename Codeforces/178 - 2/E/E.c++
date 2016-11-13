#include <iostream>
#include <algorithm>

using namespace std;

vector< pair<int, int> > edge[5000];
vector< pair<int, int> > edge_list;

int vertex_amount(int cur, int last) {
	int res = 1;
	for (int i = 0; i < edge[cur].size(); i++)
		if (edge[cur][i].first != last)
			res += vertex_amount(edge[cur][i].first, cur);
	return res;
}

int dfs(int cur, int last, unsigned long long &sum, int v_amount) {
	int res = 0;
	for (int i = 0; i < edge[cur].size; i++)
		if (edge[cur][i].first != last) {
			res += dfs(edge[cur][i].first, cur, sum);
			sum += tmp * (v_amount - tmp) * edge[cur][i].second;
		}
	return res + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, w;
		cin >> x >> y >> w; x--; y--;
		edge[x].push_back(make_pair(y, w));
		edge[y].push_back(make_pair(x, w));
		edge_list.push_back(make_pair(x, y));
	}

	unsigned long long res = 1000000000000000000ULL;

	for (int i = 0; i < edge_list.size(); i++) {
		unsigned long long sum1 = 0; sum2 = 0;
		int v1 = vertex_amount(edge_list[i].first, edge[i].second);
		int v2 = vertex_amount(edge_list[i].second, edge[i].first);

		int v1 = dfs(edge_list[i].first, edge_list[i].second, sum1, v1);
		int v2 = dfs(edge_list[i].second, edge_list[i].first, sum2, v2);

		if ()
	}
	return 0;
}