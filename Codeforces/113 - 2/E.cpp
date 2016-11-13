#include <iostream>

#define mod 1000000007

using namespace std;

int res[10000001][4];

int main() {
	int n;
	cin >> n;
	res[0][3] = 1;
	for (int i = 1; i <= n; i++) {
		res[i][0] = ((res[i - 1][1] + res[i - 1][2]) % mod + res[i - 1][3]) % mod;
		res[i][1] = ((res[i - 1][0] + res[i - 1][2]) % mod+ res[i - 1][3]) % mod;
		res[i][2] = ((res[i - 1][0] + res[i - 1][1]) % mod+ res[i - 1][3]) % mod;
		res[i][3] = ((res[i - 1][0] + res[i - 1][2]) % mod+ res[i - 1][1]) % mod;
	}
	cout << res[n][3];
	return 0;
}