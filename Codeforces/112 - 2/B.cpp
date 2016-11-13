#include <iostream>

using namespace std;

long long test(long long v, long long k) {
	long long res = v, tk = k;
	while (v / tk) {
		res += v / tk;
		tk *= k;
	}
	return res;
}

int main() {
	long long n, k;
	cin >> n >> k;
	long long left = 0, right = n * k, res = 0;
	while (left <= right) {
//		cout << left << " " << right << " " << res << endl;
		long long med = (left + right) / 2;
		long long tmed = test(med, k);
		if (tmed == n) {
			res = med;
			break;
		}
		if (tmed > n) {
			res = med;
			right = med - 1;
		} else
			left = med + 1;
	}
	cout << res << endl;
}