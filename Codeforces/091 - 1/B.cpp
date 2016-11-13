#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, k, last_found = 1;
char data[1000001];
char last1[1000001], last[1000001], cur[10000001];

void operation(char *src, char *dst)
{
	strcpy(dst, src);
	for (int i = last_found - 1; i < n - 1; i++)
		if (dst[i] == '4' && dst[i + 1] == '7')
		{
			last_found = i;
			if (i%2)
				dst[i] = '7';
			else
				dst[i + 1] = '4';
			break;
		}
}

char* iter(int i, char *last1, char *last, char *cur)
{
//	printf("%d\n", i);
	operation(last, cur);
	if (memcmp(cur + last_found, last1 + last_found, n - last_found) == 0)
	{
		int temp = (k - i - 1)%2;
		if (temp)
			printf("%s\n", last);
		else
			printf("%s\n", cur);
		exit(0);
	}
	return cur;
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", data);
	if (k == 0)
	{
		printf("%s\n", data);
		return 0;
	}
	operation(data, last1);
	if (k == 1)
	{
		printf("%s\n", last1);
		return 0;
	}
	operation(last1, last);
	if (k == 2)
	{
		printf("%s\n", last);
		return 0;
	}
	char *res;
	for (int i = 2; i < k; i++)
	{
//		if (!i%10000)
//			printf("%d\n", i);
		if (i%3 == 2)
			res = iter(i, last1, last, cur);
		if (i%3 == 0)
			res = iter(i, last, cur, last1);
		if (i%3 == 1)
			res = iter(i, cur, last1, last);
	}
	printf("%s\n", res);
	return 0;
}