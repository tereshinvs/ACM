#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

pair< int, int > a[100000];
int n, k, pl[100000];
long long b;

int main() {
//	scanf("%d%d", &n, &k);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
//	scanf("%lld", &b);
	cin >> b;
	for (int i = 0; i < n; i++) {
		int x;
//		scanf("%d", &x);
		cin >> x;
		a[i] = make_pair(-x, i);
	}
	sort(a, a + n - 1);
	for (int i = 0; i < n; i++) {
		pl[a[i].second] = i;
		a[i].first *= -1;
//		printf("%d %d\n", a[i].first, a[i].second);
	}
	long long sum = 0;
	for (int i = 0; i < k - 1; i++)
		sum += (long long)a[i].first;
/*	int left = 0, right = n - 2, res = n;
	while (left <= right) {
		int med = (left + right) / 2;*/
//	printf("%d %lld\n", sum, b);
//	cout << sum << " " << b << endl;
	int res = n;
	for (int i = 0; i < n; i++) {
		long long temp = sum;
		if (pl[i] < k - 1)
			temp = temp - a[pl[i]].first + a[k].first;
//		printf("%d %d %d\n", i, pl[i], temp);
//		cout << i << " " << pl[i] << " " << temp << endl;
		if (b < temp + a[pl[i]].first) {
			res = i + 1;
			break;
		}
	}
//	printf("%d\n", res);
	cout << res;
	return 0;
}