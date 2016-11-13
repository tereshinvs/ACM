#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

struct Man {
	int lvl;
	int parent;
	int nh;
	int num;
};

vector<int> edge[100001];
Man mans[100001];
Man man[100001];
int k = 0;
int mp[100001], fst[100001], lst[100001];
int dfs_order[1000001];
int dfs_k = 0;

set<int> tree[1000000];
set<int> res_set;

void dfs(int v, int high) {
	mans[v].lvl = high;
	fst[v] = dfs_k;
	dfs_order[dfs_k++] = v;
	for (int i = 0; i < edge[v].size(); i++) {
		dfs(edge[v][i], high + 1);
		dfs_order[dfs_k++] = v;
	}
	lst[v] = dfs_k - 1;
}

queue<int> q;
void bfs() {
	q.push(0);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		mp[v] = k;
		man[k++] = mans[v];
		for (int i = 0; i < edge[v].size(); i++)
			q.push(edge[v][i]);
	}
}

long long _hash(const char *name) {
	long long res = 0;
	long long q = 1;
	for (int i = 0; name[i]; i++, q *= 27)
		res += (name[i] - 'a') * q;
}

void construct(int v, int l, int r) {
	if (l == r) {
		tree[v].insert(man[l].nh);
//		printf("^^^ %d %d %d\n", l, r, tree[v].size());
		return;
	}
	int med = (l + r) / 2;
	construct(v * 2 + 1, l, med);
	construct(v * 2 + 2, med + 1, r);
	tree[v].insert(tree[v * 2 + 1].begin(), tree[v * 2 + 1].end());
	tree[v].insert(tree[v * 2 + 2].begin(), tree[v * 2 + 2].end());
//	printf("^^^ %d %d %d\n", l, r, tree[v].size());
}

void get(int v, int l, int r, int la, int ra) {
	printf("!!! %d %d %d %d\n", l, r, la, ra);
	if (l == la && r == ra) {
		res_set.insert(tree[v].begin(), tree[v].end());
		return;
	}
	int med = (l + r) / 2;
	if (ra <= med) {
		get(v * 2 + 1, l, med, la, ra);
		return;
	}
	if (la > med) {
		get(v * 2 + 2, med + 1, r, la, ra);
		return;
	}
	get(v * 2 + 1, l, med, la, med);
	get(v * 2 + 2, med + 1, r, med + 1, ra);
}

int main() {
	int n;
	scanf("%d\n", &n);
	mans[0].lvl = 0;
	for (int i = 1; i <= n; i++) {
		char s[30];
		int par = -1;
		scanf("%s%d", &s, &par);
		printf("%s\n", s);
		edge[par].push_back(i);
		mans[i].lvl = -1;
		mans[i].parent = par;
		mans[i].nh = _hash(s);
		mans[i].num = i;
	}
	printf("readed\n");
	dfs(0, 0);
	for (int i = 0; i < dfs_k; i++)
		printf("$$$ %d %d\n", i, dfs_order[i]);
	bfs();
	for (int i = 0; i <= n; i++)
		printf("## %d   %d %d\n",man[i].num, fst[i], lst[i]);
	construct(0, 1, n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int v, lvl;
		scanf("%d%d", &v, &lvl);
		int st = fst[v] + lvl;
		int en = lst[v] - lvl;
		if (st > en) {
			printf("0\n");
			continue;
		}
		res_set.clear();
		printf("&&& %d %d   %d %d   %d %d\n", st, en, dfs_order[st], dfs_order[en], mp[dfs_order[st]],mp[dfs_order[en]]);
//		get(0, 1, n, mp[dfs_order[st]], mp[dfs_order[en]]);
//		printf("%d\n", res_set.size());
	}
	return 0;
}