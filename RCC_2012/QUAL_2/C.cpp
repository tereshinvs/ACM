#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int a[6], b[6];

bool triangle(int x, int y, int z) {
	return x < y + z && y < x + z && z < x + y;
}

double square(int x, int y, int z) {
	double p = (x + y + z) / 2.0;
	return sqrt(p * (p - x) * (p - y) * (p - z));
}

bool test() {
	bool res = triangle(a[b[0]], a[b[1]], a[b[2]])
		&& triangle(a[b[0]], a[b[5]], a[b[4]])
		&& triangle(a[b[1]], a[b[3]], a[b[5]])
		&& triangle(a[b[2]], a[b[3]], a[b[4]]);
	if (res) {
		double sq1 = square(a[b[0]], a[b[1]], a[b[2]]),
			sq2 = square(a[b[0]], a[b[5]], a[b[4]]),
			sq3 = square(a[b[1]], a[b[3]], a[b[5]]),
			sq4 = square(a[b[2]], a[b[3]], a[b[4]]);
		return res
			&& sq1 + 10e-3 < sq2 + sq3 + sq4
			&& sq2 + 10e-3 < sq1 + sq3 + sq4
			&& sq3 + 10e-3 < sq1 + sq2 + sq4
			&& sq4 + 10e-3 < sq1 + sq2 + sq3;
	} else
		return 0;
}

int main() {
	int n;
	cin >> n;
	for (int q = 0; q < n; q++) {
		for (int i = 0; i < 6; i++)
			cin >> a[i];
		b = { 0, 1, 2, 3, 4, 5 };
		bool res = false;
		do {
			if (test())
				res = true;
		} while (next_permutation(b, b + 6));
		if (res)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}