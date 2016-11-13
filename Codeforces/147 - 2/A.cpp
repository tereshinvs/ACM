#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cur = 0, max_res = 0, last_h = -1, last_m = -1;
	for (int i = 0; i < n; i++) {
		int cur_h, cur_m;
		cin >> cur_h >> cur_m;
		if (cur_h == last_h && cur_m == last_m)
			cur++;
		else {
			if (cur > max_res)
				max_res = cur;
			cur = 1;
		}
		last_h = cur_h; last_m = cur_m;
	}
	cout << max_res << endl;
	return 0;
}