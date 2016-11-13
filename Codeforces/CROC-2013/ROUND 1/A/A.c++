#include <iostream>

using namespace std;

int main() {
	int cur = 0, curt = 0;
	int n, last_msg = 0, res_max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, c;
		cin >> t >> c;

		cur -= t - curt;
		if (cur < 0)
			cur = 0;
		else
			last_msg = t;

		cur += c;

		if (cur > res_max)
			res_max = cur;
		curt = t;
	}
	last_msg = curt + cur;

	cout << last_msg << " " << res_max << endl;
}