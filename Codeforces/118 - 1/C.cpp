#include <iostream>

using namespace std;

int mass[50], n, lvl[50][50];

int get_mass(int l, int r) {
	return mass[r] - (l ? mass[l - 1] : 0);
}

int solve(int curl, int pos, int l, int r) {
	if (curl < 0)
		return 1;
	if (lvl[curl][pos] > get_mass(l, r))
		return 0;
	else
		return solve(curl - 1, pos, l, r - 1) || solve(curl - 1, pos + 1, l + 1, r);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mass[i] = x + (i ? mass[i - 1] : 0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < n - i + 1; j++)
			cin >> lvl[i - 1][j];
	int temp = solve(n - 1, 0, 0, n - 1);
	if (temp)
		cout << "Cerealguy" << endl;
	else
		cout << "Fat Rat" << endl;
}