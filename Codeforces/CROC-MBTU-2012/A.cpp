#include <iostream>

using namespace std;

int main() {
	int n, sum1 = 0, sum2 = 0, _sum1 = 0, _sum2 = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			sum1 += x;
			_sum1 += y;
		} else {
			sum2 += x;
			_sum2 += y;
		}
	}

	if (sum1 >= _sum1)
		cout << "LIVE" << endl;
	else
		cout << "DEAD" << endl;
	if (sum2 >= _sum2)
		cout << "LIVE" << endl;
	else
		cout << "DEAD" << endl;
}