#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int res[n];
	for (int i = 0; i < n; i++)
		res[i] = 0;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		res[x - 1]++;
		res[y - 1]++;
	}

	int one = 0, two = 0, other = 0, zero = 0;
	for (int i = 0; i < n; i++) {
		if (res[i] == 1)
			one++;
		if (res[i] == 2)
			two++;
		if (res[i] == 0)
			zero++;
		if (res[i] != 1 && res[i] != 2)
			other++;
	}

	if (zero > 0)
		cout << "unknown topology";
	else if (one == 2 && other == 0)
		cout << "bus topology";
	else if (one == 0 && other == 0)
		cout << "ring topology";
	else if (one == n - 1 && other == 1)
		cout << "star topology";
	else
		cout << "unknown topology";
	cout << endl;
}