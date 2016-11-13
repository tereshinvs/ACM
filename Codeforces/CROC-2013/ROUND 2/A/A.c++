#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n; n *= 2;
	string s1, s2;
	cin >> s1 >> s2;
	int a[4] = {0};
	for (int i = 0; i < n; i++)
		a[(s1[i] - '0') * 2 + s2[i] - '0']++;

	int a1 = 0, a2 = 0;
	int i = 0;
	while (a[0] + a[1] + a[2] + a[3] > 0) {
		if (i % 2 == 0) {
			if (a[3] > 0) {
				a1++;
				a[3]--;
			} else if (a[2] > 0) {
				a1++;
				a[2]--;
			} else if (a[1] > 0)
				a[1]--;
			else
				a[0]--;
		} else {
			if (a[3] > 0) {
				a2++;
				a[3]--;
			} else if (a[1] > 0) {
				a2++;
				a[1]--;
			} else if (a[2] > 0)
				a[2]--;
			else
				a[0]--;
		}
		i++;
	}
	if (a1 > a2)
		cout << "First";
	if (a2 > a1)
		cout << "Second";
	if (a1 == a2)
		cout << "Draw";
}