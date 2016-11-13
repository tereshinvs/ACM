#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string s, res = "";
	int n;
	cin >> s >> n;
	for (int i = 0; i < s.size(); i++) {
		char c = tolower(s[i]);
		if (c < n + 97) {
			res += c - 'a' + 'A';
		} else {
			res += c;
		}
	}
	cout << res;
}