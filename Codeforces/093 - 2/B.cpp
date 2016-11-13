#include <iostream>
#include <math.h>
                 
int main()
{
	int n, res = 0, x, vl[101];
	scanf("%d", &n);
	for (int i = 0; i < 101; i++)
		vl[i] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		vl[x]++;
	}
	for (int i = 0; i < 101; i++)
		res += vl[i]/2;
	printf("%d\n", res/2);
	return 0;
}