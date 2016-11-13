#include <cstdio>
#include <map>
#include <set>

using namespace std;

int cl[100000];
set<int> res[100000];
int a[100000];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &cl[i]);
	for (int i = 0; i < n; i++) {
		cl[i]--;
		a[cl[i]] = 1;
	}
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2); v1--; v2--;
		if (cl[v1] != cl[v2]) {
			res[cl[v1]].insert(cl[v2]);
			res[cl[v2]].insert(cl[v1]);
		}
	}
	int mx = 0, mx_num = 0;
	for (int i = 0; i < 100000; i++)
		if (a[i]) {
			mx = res[i].size();
			mx_num = i + 1;
			break;
		}
	for (int i = 0; i < 100000; i++) {
		int tmp = res[i].size();
		if (tmp > mx) {
			mx = tmp;
			mx_num = i + 1;
		}
	}
	printf("%d\n", mx_num);
	return 0;
}