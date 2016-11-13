#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

map<string, int> dict;
vector<int> a[10001], vect_tmp;
int k = 1;
string data[10001];
int res[10001];

int main() {
	int m;
	ios_base::sync_with_stdio(false);
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int t1 = dict[s1];
		int t2 = dict[s2];
		if (t1 == 0) {
			data[k] = s1;
			dict[s1] = t1 = k++;
		}
		if (t2 == 0) {
			data[k] = s2;
			dict[s2] = t2 = k++;
		}
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}

	for (int i = 0; i < k; i++) {
		sort(a[i].begin(), a[i].end());
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < k; i++) {
		vect_tmp.clear();
		for (int j = 0; j < a[i].size(); j++)
			for (int q = 0; q < a[a[i][j]].size(); q++) {
				if (a[a[i][j]][q] == i)
					continue;
				int temp = lower_bound(a[i].begin(), a[i].end(), a[a[i][j]][q]) - a[i].begin();
				if (temp >= a[i].size() || a[i][temp] != a[a[i][j]][q]) {
					vect_tmp.push_back(a[a[i][j]][q]);
//					cout << endl << data[i] << ' ' << data[a[a[i][j]][q]] << endl;
				}
			}
		unique(vect_tmp.begin(), vect_tmp.end());
		for (int j = 0; j < vect_tmp.size(); j++)
			cout << endl << data[i] << " " << data[vect_tmp[j]] << " " << i << " " << vect_tmp[j];
		res[i] = vect_tmp.size();
	}

	cout << k - 1 << '\n';
	for (int i = 1; i < k; i++)
		cout << data[i] << ' ' << res[i] << '\n';
}