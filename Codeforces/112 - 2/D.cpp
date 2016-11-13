#include <stdio.h>
#include <vector>

using namespace std;

int lca_tree[10000000], ord[1000000], k = 0, n;
int alr[100000], start[100000], h[100000], frw[1000000];
vector<int> mp[100000];
vector<int> enm[100000];
int sum1_tree[10000000], sum2_tree[10000000];
int f_frw[100000], f_rev[100000];

void dfs(int v, int dep) {
	h[v] = dep;
	ord[k++] = v;
	start[v] = k - 1;
	frw[k - 1] = 1;
	alr[v] = 1;
	for (int i = 0; i < mp[v].size(); i++)
		if (!alr[mp[v][i]]) {
			f_frw[enm[v][i]] = k;
			dfs(mp[v][i], dep + 1);
			f_rev[enm[v][i]] = k;
			ord[k++] = v;
			frw[k - 1] = 0;
		}
}

void construct_lca_tree(int v, int l, int r) {
	if (l == r) {
		lca_tree[v] = ord[l];
		return;
	}
	int med = (l + r) / 2;
	construct_lca_tree(v * 2 + 1, l, med);
	construct_lca_tree(v * 2 + 2, med + 1, r);
	lca_tree[v] = h[lca_tree[v * 2 + 1]] < h[lca_tree[v * 2 + 2]] ? lca_tree[v * 2 + 1] : lca_tree[v * 2 + 2];
}

int min_lca(int v, int l, int r, int la, int ra) {
	if (l == la && r == ra)
		return lca_tree[v];
	int med = (l + r) / 2;
	if (ra <= med)
		return min_lca(v * 2 + 1, l, med, la, ra);
	if (la > med)
		return min_lca(v * 2 + 2, med + 1, r, la, ra);
	int temp1 = min_lca(v * 2 + 1, l, med, la, med);
	int temp2 = min_lca(v * 2 + 2, med + 1, r, med + 1, ra);
	return h[temp1] < h[temp2] ? temp1 : temp2;
}

int lca(int a, int b) {
	return min_lca(0, 0, k, min(start[a], start[b]), max(start[a], start[b]));
}

void construct_sum_tree(int *tree, int v, int l, int r, int _frw) {
	if (l == r) {
		tree[v] = frw[l] == _frw;
		return;
	}
	int med = (l + r) / 2;
	construct_sum_tree(tree, v * 2 + 1, l, med, _frw);
	construct_sum_tree(tree, v * 2 + 2, med + 1, r, _frw);
	tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int sum_tree(int *tree, int v, int l, int r, int la, int ra) {
	if (l == la && r == ra)
		return tree[v];
	int med = (l + r) / 2;
	if (ra <= med)
		return sum_tree(tree, v * 2 + 1, l, med, la, ra);
	if (la > med)
		return sum_tree(tree, v * 2 + 2, med + 1, r, la, ra);
	return sum_tree(tree, v * 2 + 1, l, med, la, med) + sum_tree(tree, v * 2 + 2, med + 1, r, med + 1, ra);
}

void update_sum_tree(int *tree, int v, int l, int r, int pos, int new_val) {
	if (l == r) {
		tree[v] = new_val;
		return;
	}
	int med = (l + r) / 2;
	if (pos <= med)
		update_sum_tree(tree, v * 2 + 1, l, med, pos, new_val);
	else
		update_sum_tree(tree, v * 2 + 2, med + 1, r, pos, new_val);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		v1--; v2--;
		mp[v1].push_back(v2);
		mp[v2].push_back(v1);
		enm[v1].push_back(i);
		enm[v2].push_back(i);
	}
	for (int i = 0; i < n - 1; i++)
		f_frw[i] = f_rev[i] = -1;
	dfs(0, 0);
	construct_lca_tree(0, 0, k);
	construct_sum_tree(sum1_tree, 0, 0, k, 1);
	construct_sum_tree(sum2_tree, 0, 0, k, 0);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int type, num;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d\n", &num); num--;
			update_sum_tree(sum1_tree, 0, 0, k, f_frw[num], 0);
			update_sum_tree(sum2_tree, 0, 0, k, f_rev[num], 0);
		}
		if (type == 2) {
			scanf("%d\n", &num); num--;
			update_sum_tree(sum1_tree, 0, 0, k, f_frw[num], 1);
			update_sum_tree(sum2_tree, 0, 0, k, f_rev[num], 1);
		}
		if (type == 3) {
			int v1, v2, vlca;
			scanf("%d%d", &v1, &v2); v1--; v2--;
			vlca = lca(v1, v2);
			int marked = sum_tree(sum1_tree, 0, 0, k, start[vlca], start[v1] - 1)
				- sum_tree(sum2_tree, 0, 0, k, start[vlca], start[v2] - 1);
			if (marked)
				printf("-1\n");
			else
				printf("%d\n", h[v1] + h[v2] - 2 * h[vlca]);
		}
	}
	return 0;
}