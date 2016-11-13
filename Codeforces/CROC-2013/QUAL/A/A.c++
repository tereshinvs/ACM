#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	map<int, int> data;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		data[x]++;
	}

	int res = 0;
	for (auto it: data) {
		if (it.first == 0)
			continue;
		if (it.second <= 1)
			continue;
		if (it.second == 2)
			res++;
		if (it.second > 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << res << endl;
}