#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
//unsigned long long tree[4000000], add[4000000];
//unsigned long long a[100000];
int tree[4000000], add[4000000];
int a[100000];

void construct(int v, int l, int r) {
	add[v] = 0;

	if (l == r) {
		tree[v] = a[l];
		return;
	}

	int m = (l + r) / 2;
	construct(v * 2 + 1, l, m);
	construct(v * 2 + 2, m + 1, r);
	tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

void out(int v, int l, int r) {
//	cout << l << " " << r << " " << tree[v] << endl;
	if (l == r)
		return;
	int m = (l + r) /2;
	out(v * 2 + 1, l, m);
	out (v * 2 + 2, m + 1, r);
}

void update(int v, int l, int r, int la, int ra, int x) {
	if (l == la && r == ra) {
		add[v] ^= x;
		return;
	}
	int m = (l + r) / 2;
	if (m >= ra)
		update(v * 2 + 1, l, m, la, ra, x);
	else if (m < la)
		update(v * 2 + 2, m + 1, r, la, ra, x);
	else {
		update(v * 2 + 1, l, m, la, m, x);
		update(v * 2 + 2, m + 1, r, m + 1, ra, x);
	}

	tree[v] = tree[v * 2 + 1] ^ add[v * 2 + 1] + tree[v * 2 + 2] ^ add[v * 2 + 2];
}

unsigned long long sum(int v, int l, int r, int la, int ra) {
//	scanf("%d %d\n", l, r);
//	cout << l << " " << r << endl;
	if (l == la && r == ra)
		return tree[v] ^ add[v];

	int m = (l + r) / 2;

	if (m >= ra)
		return sum(v * 2 + 1, l, m, la, ra) ^ add[v];
	else if (m < la)
		return sum(v * 2 + 2, m + 1, r, la, ra) ^ add[v];
	else
		return (sum(v * 2 + 1, l, m, la, m) + sum(v * 2 + 2, m + 1, r, m + 1, ra)) ^ add[v];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	construct(0, 0, n - 1);
//	out (0, 0, n - 1);
//	printf("construct is ok\n");
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int op, left, right, x;
//		cout << i << endl;
		scanf("%d%d%d", &op, &left, &right); left--; right--;
		if (op == 1) {
			cout << sum(0, 0, n - 1, left, right) << endl;
		} else {
			scanf("%d", &x);
			update(0, 0, n - 1, left, right, x);
		}
	}
}