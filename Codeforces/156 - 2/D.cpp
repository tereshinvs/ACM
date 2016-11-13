#include <iostream>

using namespace std;

long long all_square(long long n) {
	return n * n + (n - 1) * (n - 1);
}

long long parallel_triangle(long long n) {
	return n * n;
}

long long diagonal_triangle(long long n) {
	return n * (n + 1) / 2;
}

int main() {
	long long n, x, y, c;
	cin >> n >> y >> x >> c;
	if (c <= 1) {
		cout << 0 << endl;
		return 0;
	}
	long long cur = 1, i;
	for (i = 2; cur < c; i++) {
	/	/cout << "#" << i << endl;
		cur = all_square(i);
	//	cout << "a " << cur << endl;
		long long left = x - i, right = n - x - i + 1,
			up = y - i, down = n - y - i + 1;
	//	cout << left << " " << right << " " << up << " " << down << endl;
		if (left < 0)
			cur -= parallel_triangle(-left);
		if (right < 0)
			cur -= parallel_triangle(-right);
		if (up < 0)
			cur -= parallel_triangle(-up);
		if (down < 0)
			cur -= parallel_triangle(-down);
	//	cout << "b " << cur << endl;

		if (x + y <= i)
			cur += diagonal_triangle(-left - y);
		if (x + (n - y + 1) <= i)
			cur += diagonal_triangle(-left - (n - y) - 1);
		if ((n - x + 1) + y <= i)
			cur += diagonal_triangle(-up - (n - x) - 1);
		if ((n - x + 1) + (n - y + 1) <= i)
			cur += diagonal_triangle(-down - (n - x) - 1);

		if (cur >= c)
			break;

		//cout << "c " << cur << endl;
	}

	cout << i - 1 << endl;
	return 0;
}