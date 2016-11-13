#include <stdio.h>

const unsigned long long PRIME = 3571;

using namespace std;

char s1[1000000], s2[1000000];
unsigned long long h1[1000000], hrev[1000000], k;

int main()
	{
		gets(s1);
		gets(s2);
		int len = 0;
		for (len = 0; s1[len] != 0; len++);
		h1[0] = s1[0]; hrev[len - 1] = s1[len - 1];
		for (int i = 1; i < len; i++)
			{
				h1[i] = h1[i - 1]*PRIME + s1[i];
				hrev[len - i - 1] = hrev[len - i]*PRIME + s1[len - i - 1];
			}
		
		return 0;
	}