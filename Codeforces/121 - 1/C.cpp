#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int tree[10000000], ord[10000000], h[100000], n, k = 0, st[100000], a[100000], end[100000];
bool alr[100000];
vector< int > e[100000], e_num[100000];
int res[100000], q;

void dfs_c(int v, int curh) {
	ord[k++] = v;
	h[v] = curh;
	alr[v] = true;
	st[v] = k - 1;
	for (int i = 0; i < e[v].size(); i++) {
		if (!alr[e[v][i]]) {
			dfs_c(e[v][i], curh + 1);
			ord[k++] = v;
		}
	}
	alr[v] = false;
}

void construct(int v, int l, int r) {
	if (l == r) {
		tree[v] = ord[l];
		return;
	}
	int med = (l + r) / 2;
	construct(v * 2 + 1, l , med);
	construct(v * 2 + 2, med + 1, r);
	tree[v] = h[tree[v * 2 + 1]] < h[tree[v * 2 + 2]] ? tree[v * 2 + 1] : tree[v * 2 + 2];
}

int dfs(int v, int num) {
	int tsum = 0;
	alr[v] = true;
	for (int i = 0; i < e[v].size(); i++)
		if (!alr[e[v][i]])
			tsum += dfs(e[v][i], e_num[v][i]);
	tsum -= end[v];
	if (num != -1)
		res[num] = tsum + a[v];
	return res[num];
}

int min_v(int v, int l, int r, int la, int ra) {
	if (l == la && r == ra)
		return tree[v];
	int med = (l + r) / 2;
	if (ra <= med)
		return min_v(v * 2 + 1, l, med, la, ra);
	if (la > med)
		return min_v(v * 2 + 2, med + 1, r, la, ra);
	int temp1 = min_v(v * 2 + 1, l, med, la, med), temp2 = min_v(v * 2 + 2, med + 1, r, med + 1, ra);
	return h[temp1] < h[temp2] ? temp1 : temp2;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2); v1--; v2--;
		e[v1].push_back(v2); e[v2].push_back(v1);
		e_num[v1].push_back(i); e_num[v2].push_back(i);
	}
	dfs_c(0, 0); k--;
	construct(0, 0, k);

//	printf("Construction is ok\n");

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2); v1--; v2--;
//		printf("aaa\n");
		int lca = min_v(0, 0, k, min(st[v1], st[v2]), max(st[v1], st[v2]));
//		printf("bbb lca = %d\n", lca);
		a[v1]++; a[v2]++; end[lca] += 2;
	}
	dfs(0, -1);
//	for (int i = 0; i < n; i++)
//		printf("%d %d\n", a[i], end[i]);
	for (int i = 0; i < n - 1; i++)
		printf("%d ", res[i]);
	return 0;
}