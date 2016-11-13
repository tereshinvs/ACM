#include <stdio.h>
#include <string.h>
#include <vector>

#define mod 1000000007

using namespace std;

vector<int> a[26], x1, y1, x2, y2, *b, *c, *d, *e;
char s[100500];

int main() {
	gets(s);
	int n = strlen(s);
	char ch;
	for (int i = 0; (ch = getchar()) != '\n'; i++)
		a[ch - 'a'].push_back(i);
	int res = 0;
	b = &x1; c = &y1; d = &x2; e = &y2;
	for (int i = 0; i < n; i++) {
		(*b).clear();
		(*c).clear();
		for (int j = 0; j < a[s[i] - 'a'].size(); j++) {
			(*b).push_back(a[s[i] - 'a'][j]);
			(*c).push_back(1);
		}
		res = (res + (*c).size()) % mod;
		for (int j = i + 1; j < n; j++) {
//			printf("%d %d\n", i, j);
			(*d).clear();
			(*e).clear();
			for (int q = 0, t = 0, tsum = 0; q < a[s[j] - 'a'].size(); q++) {
				while (t < (*b).size() && (*b)[t] < a[s[j] - 'a'][q]) {
					tsum += (*c)[t];
					t++;
				}
//				if (t == b.size())
//					break;
				if (tsum) {
					(*d).push_back(a[s[j] - 'a'][q]);
					(*e).push_back(tsum);
				}
				res = (res + tsum) % mod;
			}
			b = d;
			c = e;
		}
//		printf("%d\n", res);
	}
	printf("%d\n", res);
}