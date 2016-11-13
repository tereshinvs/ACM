#include <iostream>

#define MOD 1000000007

using namespace std;

int main() {
	unsigned long long a, b, res = 0;
	cin >> a >> b;
	for (unsigned long long k = 1; k <= a; k++)
		res = (res + ((b * (b - 1) / 2) % MOD) * ((k * b + 1) % MOD)) % MOD;
	cout << res << endl;
}