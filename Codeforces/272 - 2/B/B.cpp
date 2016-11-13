#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int gcd(int a, int b) {
	int tmp;
	while (b) {
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	list<int> tmp;
	for (int i = 1; i <= 100000; i++)
		tmp.push_back(i);
	vector<vector<int> > res(n);
	vector<list<int>::iterator> to_r;
	for (int i = 0; i < n; i++) {
		to_r.clear();
		for (auto p = tmp.begin(); true; p++) {
			if (res[i].size() == 4)
				break;
			bool flag = true;
			for (int q = 0; flag && q < res[i].size(); q++)
				if (gcd(res[i][q], *p) > 1)
					flag = false;
			if (flag) {
				res[i].push_back(*p);
				to_r.push_back(p);
			}
		}
		for (int j = 0; j < 4; j++)
			tmp.erase(to_r[j]);
	}
	int res_v = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			if (res[i][j] > res_v)
				res_v = res[i][j];
	cout << res_v * k << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			cout << res[i][j] * k << " ";
		cout << endl;
	}
}