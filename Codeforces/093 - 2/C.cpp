#include <iostream>
#include <math.h>

using namespace std;

long long t1, t2, t0, x1, x2;

long double f(long long y1, long long y2)
{
	return (t1*y1 + t2*y2 + 0.0)/(y1+y2 + 0.0);
}

long long gety2(long long y1)
{
	long long left = 0, right = x2, med, res = -1;
	long double fmed;
	while (left <= right)
	{
		med = (left+right)/2;
		fmed = f(y1, med);
		if (fmed + 10e-9>= t0)
		{
			res = med;
			right = med - 1;
		}
		else
			left = med + 1;
	}
	return res;
}

int main()
{
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if (t1 == t2)
	{
		cout << min(x1, x2) << " " << min(x1, x2) << endl;
		return 0;
	}
	long long resy1 = 0, resy2 = x2, is;
	long double res = f(resy1, resy2) - t0;
	for (long long i = 1; i <= x1; i++)
	{
		is = gety2(i);
		if (is == -1) continue;
		if (f(i, is) - t0 < res || f(i, is) - t0 == res && i + is > resy1+resy2)
		{
			resy1 = i;
			resy2 = is;
			res = f(i, is) - t0;
		}
	}
	cout << resy1 << " " << resy2 << endl;
	return 0;
}