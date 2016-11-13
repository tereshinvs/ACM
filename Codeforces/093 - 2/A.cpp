#include <stdio.h>
#include <math.h>

double sqr(double t)
{
	return t*t;
}

int main()
{
	int n, k;
	double x, y, xlast, ylast, res = 0;
	scanf("%d%d%lf%lf", &n, &k, &xlast, &ylast);
	for (int i = 1; i < n; i++)
	{
		scanf("%lf%lf", &x, &y);
		res += sqrt(sqr(x - xlast) + sqr(y - ylast));
		xlast = x; ylast = y;
	}
	printf("%.8lf\n", res*k/50.0);
	return 0;
}