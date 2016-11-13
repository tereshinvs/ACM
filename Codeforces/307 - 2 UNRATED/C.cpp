#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	unsigned long long box[n + 2] = {0}, st[n + 2] = {0};
	st[0] = k;
	unsigned long long all = 0;
	for (int i = 1; i <= n; i++) {
		cin >> box[i];
		all += box[i];
	}
	unsigned int t = 0;
	while (all > 0) {
		t++;
		for (int i = n; i >= 0; i--)
			if (box[i] >= st[i]) {
				box[i] -= st[i];
				all -= st[i];
			} else {
				all -= box[i];
				unsigned long long diff = st[i] - box[i];
				st[i + 1] += diff;
				st[i] -= diff;
				box[i] = 0;
			}
	}
	cout << t << endl;
}