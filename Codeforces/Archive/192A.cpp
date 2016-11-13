#include <iostream>

using namespace std;

int main() {
	int n, temp[45000];
	cin >> n;
	for (int i = 1; i < 45000; i++)
		temp[i] = i * (i + 1) / 2;
	for (int i = 1; i < 45000; i++)
		for (int j = i; j < 45000; j++)
			if (temp[i] + temp[j] == n) {
				cout << "YES";
				return 0;
			}
	cout << "NO";
}