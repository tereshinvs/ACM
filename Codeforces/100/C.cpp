#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int a[100000], n, num[100000], vl[100000], k = 0;
int res_k = 0;
vector<int> res[100000];
priority_queue< pair<int, int> > q;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		if (!i || a[i] != a[i - 1]) {
			num[k] = a[i];
			vl[k] = 1;
			k++;
		} else
			vl[k - 1]++;
	for (int i = 0; i < k; i++)
		q.push(make_pair(vl[i], num[i]));
	pair<int, int> temp1, temp2, temp3;
	while (q.size() > 2) {
		temp1 = q.top(); q.pop();
		temp2 = q.top(); q.pop();
		temp3 = q.top(); q.pop();
		res[res_k].push_back(temp1.second);
		res[res_k].push_back(temp2.second);
		res[res_k].push_back(temp3.second);
		res_k++;
		temp1.first--;
		temp2.first--;
		temp3.first--;
		if (temp1.first)
			q.push(temp1);
		if (temp2.first)
			q.push(temp2);
		if (temp3.first)
			q.push(temp3);
	}
	printf("%d\n", res_k);
	for (int i = 0; i < res_k; i++) {
		sort(res[i].begin(), res[i].end());
		for (int j = 2; j >= 0; j--)
			printf("%d ", res[i][j]);
		printf("\n");
	}
}