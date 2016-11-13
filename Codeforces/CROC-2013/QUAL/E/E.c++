#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned long long res = 0;
string cur_s, need;
vector<int> kmp_res, edge[100000];
vector<string> edge_str;

void kmp(int start, int end) {
	if (start == 0)
		kmp_res[start] = 0;

	for (int i = start == 0 ? 1 : start; i < end; i++) {
		int j = kmp_res[i - 1];
		while (j > 0 && cur_s[j] != cur_s[i])
			j = kmp_res[j - 1];
		if (cur_s[j] == cur_s[i])
			j++;
		kmp_res[i] = j;

		if (kmp_res[i] == need.size())
			res++;
	}
}

void dfs(int v) {
	int last_lng = cur_s.size();
	cur_s.append(edge_str[v]);
	kmp(last_lng, cur_s.size());

	for (auto it: edge[v])
		dfs(it);

	cur_s.erase(last_lng, cur_s.size() - last_lng);
}

int main() {
	ios_base::sync_with_stdio(false);
	cur_s.reserve(400000);
	kmp_res.reserve(400000);

	int n;
	cin >> n;
	edge_str.resize(n);
	edge_str[0] = "";
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x >> edge_str[i]; x--;
		edge[x].push_back(i);
	}
	cin >> need;
	cur_s = need + "#";
	kmp(0, cur_s.size());

	dfs(0);

	cout << res << endl;
}