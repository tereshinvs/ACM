#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v[n];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	if (v[0].size() != 1) {
		cout << -1 << endl;
		return 0;
	}
	int lft[n], last[n];
	for (int i = 0; i < n; i++) {
		lft[i] = k - 1;
		last[i] = v[i].size() - 1;
	}
	lft[v[0][0]]++;
	vector<pair<int, int> > res;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < v[i].size(); j++) {
			while (last[i - 1] >= 0 && lft[v[i - 1][last[i - 1]]] == 0)
				last[i - 1]--;
			if (last[i - 1] < 0) {
				cout << -1 << endl;
				//cout << i << " " << j << endl;
				return 0;
			}
			res.push_back(make_pair(v[i - 1][last[i - 1]], v[i][j]));
			lft[v[i - 1][last[i - 1]]]--;
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
}