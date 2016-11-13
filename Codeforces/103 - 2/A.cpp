#include <iostream>

using namespace std;

int main() {
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = -1, mn = 10000;
	for (int i = 0; i < n; i++)
		if (a[i] > mx)
			mx = a[i];
	int res = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == mx) {
			res += i;
			for (int j = i; j; j--)
				a[j] = a[j - 1];
			a[0] = mx;
			break;
		}
	for (int i = 0; i < n; i++)
		if (a[i] < mn)
			mn = a[i];
	for (int i = n - 1; i >= 0; i--)
		if (a[i] == mn) {
			res += n - i - 1;
			break;
		}
	cout << res;
}