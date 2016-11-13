#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	double a, d;
	int n;
	cin >> a >> d >> n;
	for (int i = 1; i <= n; i++) {
		double dist = i * d;
		dist = dist - floor(dist / (4.0 * a)) * 4.0 * a;
		if (dist <= a) {
			cout << dist << " " << 0.0 << endl;
			continue;
		}
		if (a < dist && dist <= 2 * a) {
			cout << a << " " << dist - a << endl;
			continue;
		}
		if (2 * a < dist && dist <= 3 * a) {
			cout << a - (dist - 2 * a) << " " << a << endl;
			continue;
		}
		if (dist > 3 * a) {
			cout << 0 << " " << a - (dist - 3 * a) << endl;
			continue;
		}
	}
}