#include <iostream>
#include <string>

using namespace std;

void test(char ch, int &f, int &a, int &c, int &e) {
	if (ch == 'f')
		f++;
	if (ch == 'a')
		a++;
	if (ch == 'c')
		c++;
	if (ch == 'e')
		e++;
}

int main() {
	int m, n;
	cin >> n >> m;
	string A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int res = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++) {
			int f = 0, a = 0, c = 0, e = 0;
			test(A[i][j], f, a, c, e);
			test(A[i + 1][j], f, a, c, e);
			test(A[i][j + 1], f, a, c, e);
			test(A[i + 1][j + 1], f, a, c, e);
			if (f == 1 && a == 1 && c == 1 && e == 1)
				res++;
		}
	cout << res << endl;
}