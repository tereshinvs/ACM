#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dif[300], mask[300], n, m, d, num[300];
vector< int > res[300], path1[300], path2[300];

void swap(int t1, int t2) {
	int temp1 = dif[t1];
	dif[t1] = dif[t2];
	dif[t2] = temp1;
	temp1 = mask[t1];
	mask[t1] = mask[t2];
	mask[t2] = temp1;
	temp1 = num[t1];
	num[t1] = num[t2];
	num[t2] = temp1;
}

void mysort(int st, int en) {
	if (st >= en)
		return;
	int il = st, ir = en, ia = dif[rand() % (en - st) + st];
	do {
		while (dif[il] < ia)
			il++;
		while (dif[ir] > ia)
			ir--;
		if (il <= ir)
			swap(il++, ir--);
	} while (il < ir);
	if (st < ir)
		mysort(st, ir);
	if (il < en)
		mysort(il, en);
}

int main() {
	cin >> n >> d >> m;
	for (int i = 0; i < n; i++) {
		cin >> dif[i]; dif[i]--;
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			int x;
			cin >> x;
			mask[i] += 1 << (x - 1);
		}
		num[i] = i;
	}
	mysort(0, n - 1);
	int start;
	for (start = 0; start < n && dif[start] == 0; start++) {
		res[start].push_back(mask[start]);
		path1[start].push_back(-1);
		path2[start].push_back(-1);
	}
	for (int i = start; i < n; i++)
		for (int j = i - 1; j >= 0; j--)
			if (dif[j] + 1 == dif[i])
				for (int q = 0; q < res[j].size(); q++)
					if ((res[j][q] & mask[i]) == 0) {
						res[i].push_back(res[j][q] | mask[i]);
						path1[i].push_back(j);
						path2[i].push_back(q);
					}
/*	cout << "#";
	for (int i = 0; i < n; i++) {
		cout << num[i] << "       ";
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "results";*/
	int pos1 = -1, pos2 = -1;
	for (int j = n - 1; j >= 0 && dif[j] == d - 1; j--)
		for (int i = 0; i < res[j].size(); i++)
			if (res[j][i] == (1 << m) - 1) {
				pos1 = j;
				pos2 = i;
				break;
			}
	if (pos1 == -1) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "OK" << endl;
	for (int i = pos1, j = pos2; i != -1;) {
		cout << num[i] + 1 << " ";
		int i1 = i;
		i = path1[i][j];
		j = path2[i1][j];
	}
	cout << endl;
}                               