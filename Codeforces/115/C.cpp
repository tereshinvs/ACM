#include <algorithm>
#include <iostream>

using namespace std;

pair<int, int> a[105];
unsigned long long p[105];

int main() {
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].second >> a[i].first;
	sort(a, a + n);
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> p[i];
	p[t] = 100000000000000000;
	unsigned long long res = 0, alr = 0;
	for (int i = 0, j = 0; i < n;)
		if (p[j] - alr < a[i].second) {
			res += (p[j] - alr) * (j + 1) * a[i].first;
			a[i].second -= p[j] - alr;
			alr += p[j] - alr;
			j++;
		} else {
			res += (unsigned long long)a[i].second * (j + 1) * a[i].first;
			alr += a[i].second;
			i++;
		}
	cout << res << endl;
	return 0;
}