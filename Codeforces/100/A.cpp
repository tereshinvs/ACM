#include <iostream>
#include <math.h>

using namespace std;

double sqr(double t) {
	return t * t;
}

const double PI = acos(-1.0);

int main() {
	double n, R, r;
	cin >> n >> R >> r;
	if (R < r) {
		cout << "NO" << endl;
		return 0;
	}
	if (R < 2 * r) {
		if (n == 1)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
		return 0;
	}
	if (R == 2 * r) {
		if (n <= 2)
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}
	int Rs = R - r, dist = 2 * r;
	double alpha = acos((sqr(dist) - 2 * sqr(Rs)) / (-2 * sqr(Rs)));
	if (n * alpha <= 2 * PI + 10e-8)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
}