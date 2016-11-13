#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 2) {
		cout << -1 << endl;
		return 0;
	}
	cout << n << " ";
	cout << 2 << " ";
	for (int i = 1; i <= n; i++)
		if (i != 2 && i != n)
			cout << i << " ";
	cout << endl;
	return 0;
}