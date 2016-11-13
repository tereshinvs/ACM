#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = 0; j < n; j++)
			if (a[j] > a[i])
				res++;
		cout << res + 1 << " ";
	}
	cout << endl;
}