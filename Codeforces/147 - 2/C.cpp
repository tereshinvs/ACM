#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pr;

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	for (int i = 2; i <= b * 2; i++) {
		bool prim = true;
		for (int j = 0; j < pr.size() && pr[j] * pr[j] <= i; j++)
			if (i % pr[j] == 0) {
				prim = false;
				break;
			}
		if (prim)
			pr.push_back(i);
	}

	int left = 0, right = b - a + 1, med, res = -1;
	int _pst = 0;
	while (pr[_pst] < a) _pst++;
	while (left <= right) {
		med = (left + right) / 2;
		bool q = true;
		int pst = _pst;
		int pst2 = pst; //upper_bound(pr.begin(), pr.end(), a + med - 1) - pr.begin();
		//cout << "l=" << med << endl;
		for (int j = a; j <= b - med + 1; j++) {
			while (pst < pr.size() && j > pr[pst]) pst++;
			while (pst2 < pr.size() && j + med - 1 >= pr[pst2]) pst2++;
		//	cout << j << " " << j + med - 1 << " " << pst << " " << pst2 << endl;
			if (pst2 - pst < k) {
				q = false;
				break;
			}
		}
		if (q) {
			res = med;
			right = med - 1;
		} else
			left = med + 1;
	}
	cout << res << endl;
	return 0;
}