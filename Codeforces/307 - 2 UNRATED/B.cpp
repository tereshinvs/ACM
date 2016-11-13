#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void put_letters(string &a, int *la) {
	int n = a.size();
	for (int i = 0; i < n; i++)
		la[a[i] - 'a']++;
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	int la[26] = {0}, lb[26] = {0}, lc[26] = {0};
	put_letters(a, la);
	put_letters(b, lb);
	put_letters(c, lc);
	int resb = 0, resc = 0, n = a.size();
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < 26; j++)
			if (i * (unsigned long long)lb[j] > la[j]) {
				flag = false;
				break;
			}
		if (!flag)
			break;
		int mx = 100000000;
		for (int j = 0; j < 26; j++)
			if (lc[j] > 0)
				mx = min(mx, (la[j] - i * lb[j]) / lc[j]);
		if (i + mx > resb + resc) {
			resb = i;
			resc = mx;
		}
	}
	string res;
	for (int i = 0; i < resb; i++)
		res += b;
	for (int i = 0; i < resc; i++)
		res += c;
	for (int i = 0; i < 26; i++)
		la[i] -= resb * lb[i] + resc * lc[i];
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < la[i]; j++)
			res += 'a' + i;
	cout << res << endl;
}