#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long data[100000], k = 0;

void srch(unsigned long long cur, int dgk)
{
	data[k++] = cur;
	if (dgk < 10)
	{
		srch(cur*10 + 4, dgk + 1);
		srch(cur*10 + 7, dgk + 1);
	}
}

int main()
{
	srch(4, 1);
	srch(7, 1);
	sort(data, data + k);
	int l, r;
	cin >> l >> r;
	int i, j;
	for (i = 0; i < k; i++)
		if (data[i] >= l)
			break;
	for (j = 0; j < k; j++)
		if (data[j] >= r)
			break;
	if (i == j)
	{
		cout << (r - l + 1)*data[i] << endl;
		return 0;
	}
	unsigned long long res = (data[i] - l + 1)*data[i] + (r - data[j - 1]) * data[j];
	for (int q = i + 1; q < j; q++)
		res += (data[q] - data[q - 1])*data[q];
	cout << res << endl;
	return 0;
}