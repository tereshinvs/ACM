#include <iostream>
//#include <map>

#define mod 1000000007

using namespace std;

//map<long long, int> alr;

int power2n(long long n) {
	if (n == 0)
		return 1;
	long long t1 = n % 2, t2 = n / 2;
	long long temp = power2n(t2);
	if (t1)
		return ((temp * temp) % mod * 2) % mod;
	else
		return (temp * temp) % mod;
}

int main() {
	long long n;
	cin >> n;
	long long q = power2n(n);
	long long res = (q * (q + 1) / 2) % mod;
	cout << res << endl;
	return 0;
}