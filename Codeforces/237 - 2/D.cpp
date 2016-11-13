#include <iostream>
#include <string>

using namespace std;

const long long MOD = 1000000007;

struct cell {
	long long bomb, zero, bleft, bright, two;

	cell() {}
	cell(long long tbomb, long long tzero, long long tbleft, long long tbright, long long ttwo):
		bomb(tbomb % MOD), zero(tzero % MOD), bleft(tbleft % MOD), bright(tbright % MOD), two(ttwo % MOD) {}
};

int main() {
	string s;
	cin >> s;
	int n = s.size();
	cell res[n];
	if (s[0] == '*')
		res[0] = cell(1, 0, 0, 0, 0);
	if (s[0] == '0')
		res[0] = cell(0, 1, 0, 0, 0);
	if (s[0] == '1')
		res[0] = cell(0, 0, 0, 1, 0);
	if (s[0] == '2')
		res[0] = cell(0, 0, 0, 0, 0);
	if (s[0] == '?')
		res[0] = cell(1, 1, 0, 1, 0);

	for (int i = 1; i < n; i++) {
		if (s[i] == '*')
			res[i] = cell(
				res[i - 1].bomb + res[i - 1].bright + res[i - 1].two,
				0, 0, 0, 0
			);
		if (s[i] == '0') 
			res[i] = cell(
				0,
				res[i - 1].zero + res[i - 1].bleft,
				0, 0, 0
			);
		if (s[i] == '1')
			res[i] = cell(
				0, 0,
				res[i - 1].bomb,
				res[i - 1].zero + res[i - 1].bleft,
				0
			);
		if (s[i] == '2')
			res[i] = cell(
				0, 0, 0, 0,
				res[i - 1].bomb
			);
		if (s[i] == '?')
			res[i] = cell(
				res[i - 1].bomb + res[i - 1].bright + res[i - 1].two,
				res[i - 1].zero + res[i - 1].bleft,
				res[i - 1].bomb,
				res[i - 1].zero + res[i - 1].bleft,
				res[i - 1].bomb
			);
	}
//	for (int i = 0; i < n; i++)
//		cout << res[i].bomb << " " << res[i].zero << " " << res[i].bleft << " " << res[i].bright << " " << res[i].two << endl;
	cout << (res[n - 1].bomb + res[n - 1].bleft + res[n - 1].zero) % MOD << endl;
}