#include <stdio.h>
#include <algorithm>

using namespace std;

struct Ferzin {
	int x, y, num;
};

bool comp1(Ferzin t1, Ferzin t2) {
	if (t1.x < t2.x)
		return true;
	if (t1.x > t2.x)
		return false;
	if (t1.y < t2.y)
		return true;
	if (t1.y > t2.y)
		return false;
	return false;
}

bool comp11(Ferzin t1, Ferzin t2) {
	if (t1.x < t2.x)
		return true;
	if (t1.x > t2.x)
		return false;
	return false;
}

bool comp2(Ferzin t1, Ferzin t2) {
	if (t1.y < t2.y)
		return true;
	if (t1.y > t2.y)
		return false;
	if (t1.x < t2.x)
		return true;
	if (t1.x > t2.x)
		return false;
	return false;
}

bool comp21(Ferzin t1, Ferzin t2) {
	if (t1.y < t2.y)
		return true;
	if (t1.y > t2.y)
		return false;
	return false;
}

bool comp3(Ferzin t1, Ferzin t2) {
	if (t1.x + t1.y < t2.x + t2.y)
		return true;
	if (t1.x + t1.y > t2.x + t2.y)
		return false;
	if (t1.x - t1.y < t2.x - t2.y)
		return true;
	if (t1.x - t1.y > t2.x - t2.y)
		return false;
	return false;
}

bool comp31(Ferzin t1, Ferzin t2) {
	if (t1.x + t1.y < t2.x + t2.y)
		return true;
	if (t1.x + t1.y > t2.x + t2.y)
		return false;
	return false;
}

bool comp4(Ferzin t1, Ferzin t2) {
	if (t1.x - t1.y < t2.x - t2.y)
		return true;
	if (t1.x - t1.y > t2.x - t2.y)
		return false;
	if (t1.x + t1.y < t2.x + t2.y)
		return true;
	if (t1.x + t1.y > t2.x + t2.y)
		return false;
	return false;
}

bool comp41(Ferzin t1, Ferzin t2) {
	if (t1.x - t1.y < t2.x - t2.y)
		return true;
	if (t1.x - t1.y > t2.x - t2.y)
		return false;
	return false;
}

Ferzin data[100000];
int n, m, res[100000];

int main() {
	int left, right;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &data[i].x, &data[i].y);
		res[i] = 0;
		data[i].num = i;
	}
	sort(data, data + n, comp1);
	for (int i = 0; i < n; i++) {
		left = lower_bound(data, data + n, data[i], comp11) - data;
		right = upper_bound(data, data + n, data[i], comp11) - data - 1;
		if (left < i)
			res[data[i].num]++;
		if (right > i)
			res[data[i].num]++;
	}

	sort(data, data + n, comp2);
	for (int i = 0; i < n; i++) {
		left = lower_bound(data, data + n, data[i], comp21) - data;
		right = upper_bound(data, data + n, data[i], comp21) - data - 1;
		if (left < i)
			res[data[i].num]++;
		if (right > i)
			res[data[i].num]++;
	}

	sort(data, data + n, comp3);
	for (int i = 0; i < n; i++) {
		left = lower_bound(data, data + n, data[i], comp31) - data;
		right = upper_bound(data, data + n, data[i], comp31) - data - 1;
		if (left < i)
			res[data[i].num]++;
		if (right > i)
			res[data[i].num]++;
	}

	sort(data, data + n, comp4);
	for (int i = 0; i < n; i++) {
		left = lower_bound(data, data + n, data[i], comp41) - data;
		right = upper_bound(data, data + n, data[i], comp41) - data - 1;
		if (left < i)
			res[data[i].num]++;
		if (right > i)
			res[data[i].num]++;
	}

	int q[9] = {0};
	for (int i = 0; i < n; i++)
		q[res[i]]++;
	for (int i = 0; i < 9; i++)
		printf("%d ", q[i]);
	return 0;
}