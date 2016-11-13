#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	vector< pair<int, int> > res;
	for (int i = a; i <= x; i++)
		for (int j = b; j <= y; j++)
			if (i > j)
				res.push_back(make_pair(i, j));
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i].first << " " << res[i].second << endl;
}