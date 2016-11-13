#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1 && y == 2 || x == 2 && y == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}