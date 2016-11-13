#include <iostream>
#include <vector>

using namespace std;

vector< int > lst[200];
int a[200][2], n, l, res[;

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		a[i + n][1] = a[i][0];
		a[i + n][0] = a[i][1];
	}
	n *= 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && a[i][0] == a[j][1])
				lst[i].push_back(j);
}