#include <iostream>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	int xa, ya, xb, yb, n;
	cin >> xa >> ya >> xb >> yb >> n;
	if (xa > xb) {
		int temp = xa; xa = xb; xb = temp;
	}
	if (ya > yb) {
		int temp = ya; ya = yb; yb = temp;
	}
	int a[1000][3];
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	int res = 0;
	for (int i = xa; i < xb; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++)
			if (dist(i, yb, a[j][0], a[j][1]) <= a[j][2] * a[j][2]) {
				flag = true;
				break;
			}
		if (!flag)
			res++;
	}
	for (int i = yb; i > ya; i--) {
		bool flag = false;
		for (int j = 0; j < n; j++)
			if (dist(xb, i, a[j][0], a[j][1]) <= a[j][2] * a[j][2]) {
				flag = true;
				break;
			}
		if (!flag)
			res++;
	}
	for (int i = xb; i > xa; i--) {
		bool flag = false;
		for (int j = 0; j < n; j++)
			if (dist(i, ya, a[j][0], a[j][1]) <= a[j][2] * a[j][2]) {
				flag = true;
				break;
			}
		if (!flag)
			res++;
	}
	for (int i = ya; i < yb; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++)
			if (dist(xa, i, a[j][0], a[j][1]) <= a[j][2] * a[j][2]) {
				flag = true;
				break;
			}
		if (!flag)
			res++;
	}
	cout << res;
}