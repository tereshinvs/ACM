#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		long double C, F, X;
		cin >> C >> F >> X;
		long double res = 0.0, v = 2.0;
		while (X / v > C / v + X / (v + F)) {
			res += C / v;
			v += F;
		}
		res += X / v;
		cout << "Case #" << q + 1 << ": " << setprecision(20) << res << endl;
	}
}