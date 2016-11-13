#include <iostream>
#include <algorithm>

typedef unsigned long long ull;

using namespace std;

ull a[100000], t1[4000000], t2[4000000], b[100000] = {0};

void build (ull t[], ull a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (t, a, v*2, tl, tm);
		build (t, a, v*2+1, tm+1, tr);
	}
}

void update (ull t[], int v, int tl, int tr, int l, int r, ull add) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] += add;
	else {
		int tm = (tl + tr) / 2;
		update (t, v*2, tl, tm, l, min(r,tm), add);
		update (t, v*2+1, tm+1, tr, max(l,tm+1), r, add);
	}
}
 
ull get (ull t[], int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return t[v] + get (t, v*2, tl, tm, pos);
	else
		return t[v] + get (t, v*2+1, tm+1, tr, pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int data[m][3];
	for (int i = 0; i < m; i++) {
		cin >> data[i][0] >> data[i][1] >> data[i][2];
		data[i][0]--;
		data[i][1]--;
	}

	build(t1, b, 1, 0, m - 1);

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		update(t1, 1, 0, m - 1, x, y, 1);
	}

	build(t2, a, 1, 0, n - 1);
	for (int i = 0; i < m; i++)
		update(t2, 1, 0, n - 1, data[i][0], data[i][1], data[i][2] * get(t1, 1, 0, m - 1, i));

	for (int i = 0; i < n; i++)
		cout << get(t2, 1, 0, n - 1, i) << " ";
	cout << endl;
}