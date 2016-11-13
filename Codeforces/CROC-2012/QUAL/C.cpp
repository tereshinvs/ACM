#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct student {
	int time, dist, num, res;
};

student st[100000];
int n, m, tm_s[100000];

bool cmp_by_time(int s1, int s2) {
	return st[s1].time < st[s2].time;
}

/*
bool cmp_by_dist(int s1, int s2) {
	return st[s1].dist > st[s2].dist;
}*/

priority_queue< pair<int, int> > q;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &st[i].time, &st[i].dist);
		tm_s[i] = i;
		st[i].num = i;
	}

	sort(tm_s, tm_s + n);

	int j = 0, curtime = 0;
	while (j < n) {
		for (int i = 0; i < m && j < n; i++, j++) {
			q.push(make_pair(-st[tm_s[j]].dist, tm_s[j]));
			curtime = curtime < st[tm_s[j]].time ? st[tm_s[j]].time : curtime;
		}

		int eq = 0, last_dist = 0;
		while (!q.empty()) {
			pair<int, int> cur = q.top(); q.pop();
			cur.first *= -1;
			if (cur.first != last_dist) {
				curtime += (eq ? 1 + eq / 2 : 0) + cur.first - last_dist;
				eq = 0;
				last_dist = cur.first;
			}
			st[cur.second].res = curtime;
			eq++;
		}
		curtime += eq ? 1 + eq / 2 : 0;

		curtime += last_dist;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", st[i].res);
	printf("\n");

	return 0;
}