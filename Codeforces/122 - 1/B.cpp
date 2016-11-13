#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, u, r;
long long a[30], b[30], k[30], p[30];
long long res[31][2];
long long elem[31][2][30];

int main() {
	cin >> n >> u >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
	}
	for (int i = 0; i < n; i++)
		res[0][0] += a[i] * k[i];
	res[0][1] = res[0][0];
	for (int j = 0; j < n; j++)
		elem[0][0][j] = elem[0][1][j] = a[j];

	for (int q = 1; q <= u; q++) {
		int temp[30], res1 = 0, res2 = 0;
		for (int i = 0; i < n; i++) {
			elem[q][0][i] = elem[q - 1][0][i] ^ b[i];
			res1 += elem[q][0][i] * k[i];
			temp[i] = elem[q - 1][1][i] ^ b[i];
			res2 += temp[i] * k[i];
		}
		if (res2 > res1) {
			res[q][0] = res2;
			for (int j = 0; j < n; j++)
				elem[q][0][j] = temp[j];
		} else
			res[q][0] = res1;

		int temp1[30], temp2[30];
		res1 = res2 = 0;
		for (int i = 0; i < n; i++) {
			temp1[i] = elem[q - 1][0][p[i]] + r;
			res1 += temp1[i] * k[i];
			temp2[i] = elem[q - 1][1][p[i]] + r;
			res2 += temp2[i] * k[i];
		}
		if (res1 > res2) {
			for (int j = 0; j < n; j++)
				elem[q][1][j] = temp1[j];
			res[q][1] = res1;
		} else {
			for (int j = 0; j < n; j++)
				elem[q][1][j] = temp2[j];
			res[q][1] = res2;
		}
	}
	cout << max(res[u][0], res[u][1]) << endl;
}