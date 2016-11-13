#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Num {
	int val;
	int x, y;
};

int main() {
	int n;
	cin >> n;

	int c[n];
	int a[50][50], m = 0;;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
		m += c[i];
	}

	int pst[m][2];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < c[i]; j++) {
			int x;
			cin >> x; x--;
			pst[x][0] = i;
			pst[x][1] = j;
			a[i][j] = x;
		}

	vector<int> res1, res2, res3, res4;
	int k = m - 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = c[i] - 1; j >= 0; j--) {
			int t_cur = a[i][j];
			//cout << i << " " << k << " " <<j << " " << t_cur << endl;
			if (pst[k][0] == pst[t_cur][0] && pst[k][1] == pst[t_cur][1]) {
				k--;
				continue;
			}
			res1.push_back(pst[k][0] + 1);
			res2.push_back(pst[k][1] + 1);
			res3.push_back(pst[t_cur][0] + 1);
			res4.push_back(pst[t_cur][1] + 1);
			a[i][j] = k;
			a[pst[k][0]][pst[k][1]] = t_cur;
			pst[t_cur][0] = pst[k][0];
			pst[t_cur][1] = pst[k][1];
			pst[k][0] = i;
			pst[k][1] = j;
			k--;
		}
	}

	cout << res1.size() << endl;
	for (int i = 0; i < res1.size(); i++)
		cout << res1[i] << " "<< res2[i] << " "<< res3[i] << " "<< res4[i] << " " << endl;

	return 0;
}