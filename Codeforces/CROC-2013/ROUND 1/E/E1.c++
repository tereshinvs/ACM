#include <iostream>
#include <vector>

using namespace std;

int t[4000000];
int a[100000], b[100000];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = -1;
	} else {
		t[v] = -1;
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
	}
}

void push (int v, int tl, int tr) {
	if (t[v] != -1) {
		int last = t[v];
		t[v * 2] = last;
		t[v*2 + 1] = last + (tl + tr) / 2 - tl + 1;
		t[v] = -1;
	}
}
 
void update (int v, int tl, int tr, int l, int r, int color) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] = color;
	else {
		push (v, tl, tr);
		int tm = (tl + tr) / 2;
		int lcolor, rcolor;
		if (r <= tm) {
			lcolor = color;
			rcolor = -1;
		}
		if (l > tm) {
			lcolor = -1;
			rcolor = color;
		}
		if (l <= tm && r > tm) {
			lcolor = color;
			rcolor = color + tm - l + 1;
		}
		update (v*2, tl, tm, l, min(r,tm), lcolor);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, rcolor);
	}
}
 
int get (int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v] == -1 ? b[pos] : a[t[v] + pos - tl];
	push (v, tl, tr);
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return get (v*2, tl, tm, pos);
	else
		return get (v*2+1, tm+1, tr, pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	build(1, 0, n - 1);

	for (int q = 0; q < m; q++) {
		int t, x, y, k;
		cin >> t;
		if (t == 1) {
			cin >> x >> y >> k; x--; y--;
			update(1, 0, n - 1, y, y + k - 1, x);
		} else {
			cin >> x;
			int tmp = get(1, 0, n - 1, x - 1);
//			cout << "<" << tmp << ">" << endl;
			cout << tmp << endl;
//			cout << "<" << (tmp == -1 ? b[x - 1] : a[tmp]) << ">" << endl;
		}
	}
}