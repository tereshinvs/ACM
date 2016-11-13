#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> one, two; 
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1)
			one.push_back(y);
		else
			two.push_back(y);
	}

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	int res = 1000000000;
	int cur_one = 0;
	for (int i = 0; i <= one.size(); i++) {
		int cur_two = 0;
		for (int j = 0; j <= two.size(); j++) {
			int tmp = one.size() - i + 2 * (two.size() - j);
			if (tmp >= cur_one + cur_two)
				if (tmp < res)
					res = tmp;
			if (j < two.size())
				cur_two += two[j];
		}
		if (i < one.size())
			cur_one += one[i];
	}

	cout << res << endl;
}