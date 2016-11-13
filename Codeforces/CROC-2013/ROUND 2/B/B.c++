#include <iostream>
#include <vector>

const unsigned MOD = 1000000007;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	unsigned n, m, k;

	vector<vector<unsigned> > res1, res2;

	cin >> n >> m >> k;
	if (n + m - 1 > k) {
		cout << 0 << endl;
		return 0;
	}

	unsigned a[n][m];
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < m; j++)
			cin >> a[i][j];

	res1.resize(m);
	res2.resize(m);
	for (unsigned i = 0; i < m; i++) {
		res1[i].resize(1 << k);
		res2[i].resize(1 << k);
	}

	for (unsigned i = 0; i < (1 << k); i++)
		res1[0][i] = 0;
	if (a[0][0] == 0)
		for (unsigned i = 0; i < k; i++)
			res1[0][1 << i] = 1;
	else
		res1[0][1 << a[0][0]] = 1;

	for (unsigned i = 1; i < m; i++)
		if (a[0][i] == 0) {
			for (unsigned q = 0; q < (1 << k); q++)
				res1[i][q] = 0;
			for (unsigned j = 0; j < k; j++) {
				for (unsigned q = 0; q < (1 << k); q++)
					if (((1 << j) & q) == 0)
						res1[i][(1 << j) | q] = (res1[i][(1 << j) | q] + res1[i - 1][q]) % MOD;
			}
		} else {
			for (unsigned q = 0; q < (1 << k); q++)
				res1[i][q] = 0;
			for (unsigned q = 0; q < (1 << k); q++)
				if (((1 << (a[0][i] - 1)) & q) == 0)
					res1[i][(1 << (a[0][i] - 1)) | q] = (res1[i][(1 << (a[0][i] - 1)) | q] + res1[i - 1][q]) % MOD;
		}

	for (unsigned q = 1; q < n; q++) {
		vector<vector<unsigned> > &r1 = q % 2 == 1 ? res1 : res2;
		vector<vector<unsigned> > &r2 = q % 2 == 0 ? res1 : res2;

		for (unsigned i = 0; i < m; i++) {
			for (unsigned w = 0; w < (1 << k); w++)
				r2[i][w] = 0;
			if (a[q][i] == 0) {
				for (unsigned j = 0; j < k; j++) {
					for (unsigned q1 = 0; q1 < (1 << k); q1++)
						for (unsigned q2 = 0; q2 < (1 << k); q2++)
							if (((1 << j) & q1) == 0 && ((1 << j) & q2) == 0) {
								unsigned t = (1 << j) | q1 | q2;
								r2[i][t] = (r2[i][t] + r1[i][q1] + (i > 0 ? r2[i - 1][q2] : 0)
									- (i > 0 ? r1[i - 1][q1 & q2] : 0)) % MOD;
							}
				}
			} else {
				for (unsigned q1 = 0; q1 < (1 << k); q1++)
					if (((1 << (a[q][i] - 1)) & q1) == 0) {
						int t = (1 << (a[q][i] - 1)) | q1;
						r2[i][t] = (r2[i][t] + r1[i][q1]) % MOD;
						r2[i][t] = (r2[i][t] + (i > 0 ? r2[i - 1][q1] : 0)) % MOD;
					}
			}
		}
	}

	vector<vector<unsigned> > tr = n % 2 == 1 ? res1 : res2;
	unsigned res = 0;
	for (unsigned i = 0; i < (1 << k); i++)
		res = (res + tr[m - 1][i]) % MOD;
	cout << res << endl;
}