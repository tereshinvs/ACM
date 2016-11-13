#include <iostream>

using namespace std;

int alr[100000];

int main() {
	int a, b, m, r;
	cin >> a >> b >> m >> r;

	for (int i = 0; i <= m; i++)
		alr[i] = -1;

	alr[r] = 0;

	for (int i = 1; i <= m; i++) {
		r = (a * r + b) % m;

		if (alr[r] != -1) {
			cout << i - alr[r] << endl;
			return 0;
		}

		alr[r] = i;
	}

	return 0;
}