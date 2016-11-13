#include <iostream>

using namespace std;

long long t0, t1, t2, x1, x2;

double f(long long y1, long long y2)
{
	return (t1*y1 + t2*y2)/(y1+y2+0.0);
}

int main()
{
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	for (int i = 0; i < x2; i++)
	{
		temp = i*(t2-t0+0.0)/(t0-t1+0.0);
		t1 = min(floor(temp), x1);
		if (f(t1, i) - t0 < res && t1 + i > resy1 + resy2)
		{
			res = f(t1, i)
		}
	}
}