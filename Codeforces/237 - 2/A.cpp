#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	char d = s[0][0], nd = s[0][1];
	if (d == nd) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (s[i][i] != d || s[i][n - i - 1] != d) {
			cout << "NO" << endl;
			return 0;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && j != n - i - 1 && s[i][j] != nd) {
				cout << "NO" << endl;
				return 0;
			}
	cout << "YES" << endl;
}