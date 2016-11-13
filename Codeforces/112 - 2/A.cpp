#include <iostream>

using namespace std;

int main() {
	int n;
	int a[200][2];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1];
	int res = 0;
	for (int i = 0; i < n; i++) {
		bool left = false, right = false, down = false, up = false;
		for (int j = 0; j < n; j++)
			if (a[j][0] == a[i][0] && a[j][1] > a[i][1])
				up = true;
		for (int j = 0; j < n; j++)
			if (a[j][0] == a[i][0] && a[j][1] < a[i][1])
				down = true;
		for (int j = 0; j < n; j++)
			if (a[j][1] == a[i][1] && a[j][0] > a[i][0])
				right = true;
		for (int j = 0; j < n; j++)
			if (a[j][1] == a[i][1] && a[j][0] < a[i][0])
				left = true;
		res += up && down && left && right;
	}
	cout << res << endl;
}