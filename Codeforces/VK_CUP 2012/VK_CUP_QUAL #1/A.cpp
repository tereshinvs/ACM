#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int res = 0;
	for (int i = 0; i < n; i++)
		res += a[i] && a[i] >= a[k - 1];
	cout << res << endl;
	return 0;
}