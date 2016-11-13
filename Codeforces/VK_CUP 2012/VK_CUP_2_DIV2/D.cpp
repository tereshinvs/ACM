#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, h;
pair<int, int> lem[100000];
int mas_s[100000], sp_s[100000];
int mas_pos[100000];

bool cmp_mas(int t1, int t2) {
	return (lem[t1].second > lem[t2].second) || (lem[t1].second == lem[t2].second && lem[t1].first > lem[t2].first);
}

bool cmp_s(int t1, int t2) {
	return (lem[t1].first > lem[t2].first) || (lem[t1].first == lem[t2].first && lem[t1].second > lem[t2].second);
}

int main() {
	scanf("%d%d%d", &n, &k, &h);
	for (int i = 0; i < n; i++)
		scanf("%d", &lem[i].first)
	for (int i = 0; i < n; i++)
		scanf("%d", &lem[i].second);
	for (int i = 0; i < n; i++)
		mas_s[i] = sp_s[i] = i;
	sort(mas_s, mas_s + n, cmp_mas);
	sort(sp_s, sp_s + n, cmp_sp);
	for (int i = 0; i < n; i++)
		mas_pos[mas_s[i]] = i;
	int j = 0;
	for (int i = 0; i < k; i++) {
		while (true) 
	}
}