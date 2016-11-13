#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n - 1; i++)
		a[i] = 1;
	a[n - 1] = 0;

	for (int q = 0; q < k; q++) {
		for (int i = 0; i < n; i++) {
			int l = i, r = n - 1, res = -1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (a[i] + a[m] <= n - i - 1) {
					res = m;
					r = m - 1;
				} else
					l = m + 1;
			}
			a[i] += a[res];
			cout << res + 1 << " ";
		}
		cout << endl;
	}
}