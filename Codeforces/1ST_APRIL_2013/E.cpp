#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int h = 0, q = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == h)
			h++;
		else
			q++;
	if (!(h % 2 == 0 ^ q % 2 == 0))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}