#include <iostream>
#include <vector>

using namespace std;

int t[4000000], c1[4000000], c2[4000000];
int a[100000], b[100000];

void build (int a[], int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
		c1[v] = c2[v] = -1;
	} else {
		c1[v] = c2[v] = -1;
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
	}
}
 
void update (int v, int tl, int tr, int l, int r, int lc, int rc) {
	if (l > r || rc < lc)
		return;
	if (l == tl && tr == r) {
		c1[v] = lc;
		c2[v] = rc;
	} else {
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), lc, lc + min(r, tm) - l + 1);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, lc + min(r, tm) - l + 2, rc);
	}
}
 
int get (int v, int tl, int tr, int pos, int cur) {
	if (tl == tr) {
		if (c1[v] != 1)
			cur = c1[v] + pos -tl;
		cout << "$" << cur << endl;
		return cur == -1 ? b[pos] : a[cur];
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return get (v*2, tl, tm, pos, c1[v] == -1 ? cur : (c1[v] + pos - tl));
	else
		return get (v*2+1, tm+1, tr, pos, c1[v] == -1 ? cur : (c1[v] + pos - tl));
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	build(b, 1, 0, n - 1);

	for (int q = 0; q < m; q++) {
		int t, x, y, k;
		cin >> t;
		if (t == 1) {
			cin >> x >> y >> k; x--; y--;
			update(1, 0, n - 1, y, y + k - 1, x, x + k - 1);
		} else {
			cin >> x;
			cout << "<" << get(1, 0, n - 1, x - 1, -1) << ">" << endl;
		}
	}
}