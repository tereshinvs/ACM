#include <iostream>
#include <math.h>

using namespace std;

int tabs(int t)
{
	return t < 0 ? -t : t;
}

int f(int a, int b)
{
	return (int)floor(a/(2*b+0.0));
}

int main()
{
	int a, b, x1, y1, x2, y2, x1s, y1s, x2s, y2s;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	x1s = f((x1+y1), b);
	y1s = f((x1-y1), a);
	x2s = f((x2+y2), b);
	y2s = f((x2-y2), a);
	cout << max(tabs(x1s-x2s), tabs(y2s-y1s)) << endl;
}