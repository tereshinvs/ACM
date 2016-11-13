#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char s[1000001];
int k;
long long t[1000001];
long long res = 0;

int main() {
	scanf("%d\n", &k);
	char c;
	int lng = 0;
	for (int i = 0; (c = getchar()) != '\n'; i++)
		s[lng++] = c;
	s[lng] = 0;
	for (int i = 0; i <= 1000000; i++)
		t[i] = 0;
	t[0] = 1;
	int cur = 0;
	for (int i = 0; i < lng; i++) {
		if (s[i] == '1')
			cur++;
		if (cur >= k)
			res += t[cur - k];
		t[cur]++;
	}
	cout << res << endl;
}