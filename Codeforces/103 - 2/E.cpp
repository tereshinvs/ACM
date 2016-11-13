#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
	int x, y, num;
};

int n, m;
point xy[100000];
bool temp[100000], temp1[100000];
vector<int> res;

int abs(int t) {
	return t > 0 ? t : -t;
}

int min(int t1, int t2) {
	return t1 < t2 ? t1 : t2;
}

bool cmp(point p1, point p2) {
	if (p1.x < p2.x)
		return true;
	if (p1.x > p2.x)
		return false;
	return p1.y < p2.y;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &y, &x); x = n - x; y = n - y;
		xy[i].x = n - y - x - 1;
		xy[i].y = x;
		xy[i].num = i + 1;
	}
	for (int i = 0; i < n; i++)
		temp[i] = true;
	sort(xy, xy + m, cmp);
	int cur = 0;
	for (cur; cur < m && xy[cur].x == 0; cur++) {
		res.push_back(xy[cur].num);
		temp[xy[cur].y] = false;
	}
	for (int i = 0; i < m; i++)
		printf("%d %d %d\n", xy[i].num, xy[i].x, xy[i].y);
	for (int i = 1; i < n; i++) {
		printf("****************************************\n");
		for (int j = n - i; j >= 0; j--)
			printf("%d", temp[j]);
		printf("\n");
		while (cur < m && xy[cur].x == i) {
			if (temp[xy[cur].y]) {
				res.push_back(xy[cur].num);
				temp[xy[cur].y] = false;
				cur++;
				continue;
			}
			if (temp[xy[cur].y + 1]) {
				res.push_back(xy[cur].num);
				temp[xy[cur].y + 1] = false;
				cur++;
				continue;
			}
			cur++;
		}
		for (int j = 0; j < n - i; j++)
			temp1[j] = temp[j + 1] || temp[j];
		for (int j = 0; j < n - i; j++)
			temp[j] = temp1[j];
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
}