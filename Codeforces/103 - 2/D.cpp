#include <queue>
#include <stdio.h>
#include <vector>

#define INF 1000000000

using namespace std;

vector< pair<int, int> > mp[100000];
int n, m, s, res[100000];
priority_queue< pair<int, int> > q;
bool alr[100000];

void dijkstra(int start) {
	for (int i = 0; i < n; i++) {
		alr[i] = false;
		res[i] = i == start ? 0 : INF;
		q.push(make_pair(-res[i], i));
	}
	for (int w = 0; w < n; w++) {
		while (alr[q.top().second])
			q.pop();
		int cur = q.top().second;
		alr[cur] = true;
		for (int i = 0; i < mp[cur].size(); i++)
			if (res[mp[cur][i].first] > res[cur] + mp[cur][i].second) {
				res[mp[cur][i].first] = res[cur] + mp[cur][i].second;
				q.push(make_pair(-res[mp[cur][i].first], mp[cur][i].first));
			}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s); s--;
	for (int i = 0; i < m; i++) {
		int v1, v2, lng;
		scanf("%d%d%d", &v1, &v2, &lng); v1--; v2--;
		mp[v1].push_back(make_pair(v2, lng));
		mp[v2].push_back(make_pair(v1, lng));
	}
	dijkstra(s);
	int l, res_t = 0;
	scanf("%d", &l);
	for (int i = 0; i < n; i++)
		if (res[i] == l)
			res_t++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < mp[i].size(); j++) {
			if (i > mp[i][j].first)
				continue;
			int temp = mp[i][j].second - (l - res[i]);
			if (temp > 0 && l > res[i] && res[mp[i][j].first] + temp >= l)
				res_t++;
			if (temp == l - res[i] && temp > 0)
				continue;
			temp = mp[i][j].second - (l - res[mp[i][j].first]);
			if (temp > 0 && l > res[mp[i][j].first] && res[i] + temp >= l)
				res_t++;
		}
	printf("\n%d\n", res_t);
	return 0;
}