#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[3] = {0, 0, 0};
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i % 3] += x;
	}

	if (a[0] > a[1] && a[0] > a[2])
		cout << "chest" << endl;
	if (a[1] > a[0] && a[1] > a[2])
		cout << "biceps" << endl;
	if (a[2] > a[1] && a[2] > a[0])
		cout << "back" << endl;
	return 0;
}