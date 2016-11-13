#include <iostream>
#include <algorithm>

using namespace std;

int a[2000];

int main() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int res = a[n - k1] - a[n - k1 - 1];
	cout << res << endl;
}