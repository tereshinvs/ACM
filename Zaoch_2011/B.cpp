#include <iostream>

using namespace std;

long long f(long long cur, long long a, long long b) {
	if (cur > b)
		return -1;
	if (cur >= a)
		return cur;
	long long temp;
	if ((temp = f(cur * 3, a, b)) != -1)
		return temp;
	if ((temp = f(cur * 3 + 1, a, b)) != -1)
		return temp;
	if ((temp = f(cur * 3 + 2, a, b)) != -1)
		return temp;
	return -1;
}

int main() {
	long long a, b, temp;
	cin >> a >> b;
	if ((temp = f(1, a, b)) != -1) {
		cout << temp << endl;
		return 0;
	}
	if ((temp = f(2, a, b)) != -1) {
		cout << temp << endl;
		return 0;
	}
}