#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int res = 0, j = 0;
	for (int i = 0; i < n; i++) {
		while (j < m && a[i] > b[j])
			j++;
		if (j >= m) {
			cout << n - i << endl;
			return 0;
		}
		j++;
	}
	cout << 0 << endl;
	return 0;
}