#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU {
	vector<int> parent;

	DSU(int n = 0) {
		parent.resize(n);
		for (int i = 0; i < n; i++)
			make_set(i);
	}

	DSU(const DSU &arg) {
		parent = arg.parent;
	}

	void make_set(int k) {
		parent[k] = k;
	}

	int find_set(int k) {
		if (k == parent[k])
			return k;
		else
			return parent[k] = find_set(parent[k]);
	}

	void union_set(int k1, int k2) {
		int p1 = find_set(k1);
		int p2 = find_set(k2);
		if (p1 != p2)
			if (rand() % 2 == 1)
				parent[p1] = p2;
			else
				parent[p2] = p1;
	}

	int merge_set(DSU &t) const {
		DSU tmp(*this);
		for (int i = 0; i < parent.size(); i++)
			tmp.union_set(i, t.find_set(i));
		int res_a = 0;
		for (int i = 0; i < parent.size(); i++)
			if (i == tmp.find_set(i))
				res_a++;
		return res_a;
	}
};

vector<DSU> ldsu, rdsu;
vector< pair<int, int> > data;

int main() {
	srand(time(NULL));

	int n, m;
	cin >> n >> m;
	ldsu.resize(m + 1);
	rdsu.resize(m + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		data.push_back(make_pair(x, y));
	}

	ldsu[0] = DSU(n);
	for (int i = 1; i < m; i++) {
		ldsu[i] = ldsu[i - 1];
		ldsu[i].union_set(data[i - 1].first, data[i - 1].second);
	}

	rdsu[m] = DSU(n);
	for (int i = m - 1; i >= 0; i--) {
		rdsu[i] = rdsu[i + 1];
		rdsu[i].union_set(data[i].first, data[i].second);
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		cout << ldsu[x].merge_set(rdsu[y + 1]) << endl;
	}
}