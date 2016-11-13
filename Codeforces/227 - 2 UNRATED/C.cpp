#include <string>
#include <iostream>

using namespace std;

int cmp(string &s, int l1, int r1, int l2, int r2) {
	while (l1 < r1 && s[l1] == '0')
		l1++;
	while (l2 < r2 && s[l2] == '0')
		l2++;
	if (r1 - l1 < r2 - l2)
		return -1;
	if (r1 - l1 > r2 - l2)
		return 1;
	for (int i = l1, j = l2; i < r1; i++, j++) {
		if (s[i] < s[j])
			return -1;
		if (s[i] > s[j])
			return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	int res = 1, n = s.size(), lastl = n - 1, lastr = n;
	while (lastl > 0) {
		res++;
		int l = 0, r = lastl - 1, m, tres = -1;
		while (l <= r) {
			m = (l + r) / 2;
			int tmp = cmp(s, m, lastl, lastl, lastr);
			if (tmp >= 0) {
				tres = m;
				l = m + 1;
			} else
				r = m - 1;
		}
		if (tres == -1) {
			cout << res - 1 << endl;
			return 0;
		}
		lastr = lastl;
		lastl = tres;
	}

	cout << res << endl;
}