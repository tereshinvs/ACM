#include <iostream>

using namespace std;

unsigned long long count_zero(unsigned long long n, unsigned long long m) {
}

int main() {
	unsigned long long n, k, l, m;
	cin >> n >> k >> l >> m;
	if (k >= ((unsigned long long)1 << l)) {
		cout << 0 << endl;
		return 0;
	}
	int a[l];
	for (int i = 0; i < l; i++) {
		a[i] = k % 2;
		k /= 2;
	}

	unsigned long long zero = count_zero(n, m);
}