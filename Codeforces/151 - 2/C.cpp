#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> b;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int q = 0;
	while (1) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
//			cout << i << endl;
			if (q == k)
				break;
			sum += a[i];
			if (b.count(sum) == 0) {
				cout << i + 1 << " ";
				for (int j = 0; j <= i; j++)
					cout << a[j] << " ";
				cout << endl;
				q++;
				b.insert(sum);
			}
		}
		if (q == k)
			break;
		next_permutation(a, a + n);
	}
}