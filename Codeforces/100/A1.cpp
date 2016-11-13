#include <iostream>
#include <math.h>

using namespace std;

double sqr(double t) {
	return t * t;
}

const double PI = acos(-1.0);

int main() {
	int n, R, r;
	cin >> n >> R >> r;
	if (R < r) {
		cout << "NO";
		return 0;
	}
	if (n == 1) {
		if (R >= r)
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}
	if (n == 2) {
		if (R >= 2 * r)
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}
	double nD;
	if (n%2)
		nD = sqrt(sqr(R - r) - sqr(r)) + R - r;
	else
		nD = 2 * (R - r);
	if (nD <= 2 * R)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
}