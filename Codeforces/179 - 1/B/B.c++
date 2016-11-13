#include <iostream>

typedef unsigned long long ull;

using namespace std;

ull data[500][500] = { 1000000000 } ;
ull res[500][500] = {1000000000};
bool exist[500] = { false };
int n;

ull mmin(ull t1, ull t2) {
	return t1 > t2 ? t2 : t1;
}

void dijkstra_from(int v, int ex_n) {
	bool alr[500] = { false };
	for (int i = 0; i < ex_n; i++) {
		int target = -1, t_min = 1000000001;
		for (int j = 0; j < n; j++)
			if (exist[j] && !alr[j] && res[v][j] < t_min)
				t_min = res[v][j], target = j;
		alr[target] = true;

		for (int j = 0; j < n; j++)
			if (exist[j])
				res[v][j] = mmin(res[v][j], res[v][target] + res[target][j]);
	}
}

void dijkstra_to(int v, int ex_n) {
	bool alr[500] = { false };
	for (int i = 0; i < ex_n; i++) {
		int target = -1, t_min = 1000000001;
		for (int j = 0; j < n; j++)
			if (exist[j] && !alr[j] && res[j][v] < t_min)
				t_min = res[j][v], target = j;
		alr[target] = true;

		for (int j = 0; j < n; j++)
			if (exist[j])
				res[j][v] = mmin(res[j][v], res[j][target] + res[target][v]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> data[i][j];

	for (int i = 0; i < n; i++)
		data[i][i] = 0;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	ull res_step[n];

	for (int q = n - 1; q >= 0; q--) {
		exist[a[q]] = true;
		res[a[q]][a[q]] = 0;
		for (int i = 0; i < n; i++) {
			res[a[q]][i] = data[a[q]][i];
			res[i][a[q]] = data[i][a[q]];
		}
		dijkstra_from(a[q], n - q);
		dijkstra_to(a[q], n - q);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!exist[i] || !exist[j] || i == a[q] || j == a[q])
					continue;
				res[i][j] = mmin(res[i][j], res[i][a[q]] + res[a[q]][j]);
			}

		ull tmp = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (exist[i] && exist[j])
					tmp += res[i][j];
		res_step[q] = tmp;
	}

	for (int i = 0; i < n; i++)
		cout << res_step[i] << " ";
	cout << endl;
}