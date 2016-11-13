#include <stdio.h>
#include <string.h>

char s[1000001];
int pr[1000001], n;

void prefix()
{
	pr[0] = 0;
	for (int i=1; i<n; ++i) {
		int j = pr[i-1];
		while (j > 0 && s[i] != s[j])
			j = pr[j-1];
		if (s[i] == s[j])  ++j;
		pr[i] = j;
	}
}

int main()
{
	scanf("%s", s); n = strlen(s);
	prefix();
	int flag;
	for (int i = pr[n - 1]; i > 0; i = pr[i - 1])
	{
		flag = 0;
//		printf("%d\n", i);
		for (int j = 1; j < n - 1; j++)
			for (int j1 = pr[j]; j1 > 0; j1 = pr[j1 - 1])
				if (j1 == i)
				{
					flag = 1;
					goto t;
				}
t:
		if (flag)
		{
			for (int j = 0; j < i; j++)
				printf("%c", s[j]);
			printf("\n");
			return 0;
		}
	}
	printf("Just a legend\n");
	return 0;
}