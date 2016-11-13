#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
};

point a[8], temp1[4], temp2[4];
int q[] = {0, 1, 2, 3, 4, 5, 6, 7};

int sqr(int t) {
	return t*t;
}

int length(point p1, point p2) {
	return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}

void test() {
	int len = length(temp1[0], temp1[3]);
	for (int i = 0; i < 3; i++)
		if (length(temp1[i], temp1[i+1]) != len)
			return;
	if (length(temp1[0], temp1[2]) != length(temp1[1], temp1[3]))
		return;

	if (length(temp2[0], temp2[1]) != length(temp2[2], temp2[3]))
		return;
	if (length(temp2[2], temp2[1]) != length(temp2[0], temp2[3]))
		return;
	if (length(temp2[0], temp2[2]) != length(temp2[1], temp2[3]))
		return;
	cout << "YES" << endl;
	for (int i = 0; i < 4; i++)
		cout << q[i] + 1 << " ";
	cout << endl;
	for (int i = 4; i < 8; i++)
		cout << q[i] + 1 << " ";
	cout << endl;
	exit(0);
}

int main() {
	for (int i = 0; i < 8; i++)
		cin >> a[i].x >> a[i].y;
	do {
		for (int i = 0; i < 4; i++)
			temp1[i] = a[q[i]];
		for (int i = 0; i < 4; i++)
			temp2[i] = a[q[i + 4]];
		test();
	} while (next_permutation(q, q + 8));
	cout << "NO" << endl;
	return 0;
}                     