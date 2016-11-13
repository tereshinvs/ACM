#include <iostream>

using namespace std;

int main()
{
	int a, b, n, res = 0;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		if (i - 1 >= a && n - i <= b)
			res++;
	cout << res << endl;
}