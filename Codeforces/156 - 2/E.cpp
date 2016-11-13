#include <iostream>

using namespace std;

int get_turns(long long n) {
	if (n <= 3)
		return 0;
	long long left = 4, right = 27;
	int k = 1;
	while (right < n) {
		long long tmp = left * left * left * left;
		left = right + 1;
		right = tmp;
	}
	return k;
}

int main() {
	int n;
	cin >> n;
	int turns = 0;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		turns += get_turns(x);
	}
	if (turns % 2 == 0)
		cout << "Rublo" << endl;
	else
		cout << "Furlo" << endl;
	return 0;
}