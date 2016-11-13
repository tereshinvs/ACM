#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	pair<int, int> data[50];
	for (int i = 0; i < n; i++) {
		int pr, tim;
		cin >> pr >> tim;
		data[i] = make_pair(-pr, tim);
	}
	sort(data, data + n);
	int cur_k = 1, am = 1;
	for (int i = 1; i < n; i++) {
		if (data[i] == data[i - 1])
			am++;
		else {
			if (cur_k <= k && i >= k) {
				cout << am << endl;
				return 0;
			}
			cur_k = i + 1;
			am = 1;
		}
	}
	if (cur_k <= k && n >= k) {
		cout << am << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}