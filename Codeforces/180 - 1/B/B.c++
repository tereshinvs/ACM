#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	int mx = -1, cmx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > mx) {
			mx = x;
			cmx = 1;
		} else if (x == mx)
			cmx++;
	}
}