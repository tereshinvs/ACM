#include <iostream>
#include <vector>

using namespace std;

pair<int, int> mem[1000];
vector<int> fls[2000];
vector< pair< int, int > > resk;

int main() {
	for (int i = 0; i < 1000; i++)
		mem[i] = make_pair(1000, 0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int lng;
		cin >> lng;
		for (int j = 0; j < lng; j++) {
			int x;
			cin >> x; x--;
			mem[x] = make_pair(i, j);
			fls[i].push_back(x);
		}
	}
	int q = 0, res = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < fls[i].size(); j++) {
			if (q == fls[i][j]) {
				q++;
				continue;
			}
			int fr = 0;
			for (int w = q; w < n; w++)
				if (mem[w].first == 1000) {
					fr = w;
					break;
				}
			if (fr == q) {
				resk.push_back(make_pair(fls[i][j] + 1, q + 1));
				mem[fls[i][j]].first = 1000;
				q++;
				continue;
			}
			resk.push_back(make_pair(q + 1, fr + 1));
			fls[mem[q].first][mem[q].second] = fr;
			mem[fr] = mem[q];
			resk.push_back(make_pair(fls[i][j] + 1, q + 1));
			mem[fls[i][j]].first = 1000;
			q++;
		}
	cout << resk.size() << endl;
	for (int i = 0; i < resk.size(); i++)
		cout << resk[i].first << " " << resk[i].second << endl;
	return 0;
}