#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector< pair< pair<int, int>, int> > a;
	int n;
	scanf("%d", &n);
	for (int i =0 ;i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a.push_back(make_pair(make_pair(x, -y), i));
	}

	sort(a.begin(), a.end());

	bool res = true;
	for (int i = 0; i < n; i++)
		if (-a[0].first.second < -a[i].first.second)
			res = false;

	if (res)
		printf("%d\n", a[0].second + 1);
	else
		printf("-1\n");
}