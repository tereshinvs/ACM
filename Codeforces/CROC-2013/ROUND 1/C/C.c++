#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int num[6] = { 0 };
int lng = 0;
vector<int> good;
vector<int> even, odd;
vector< pair<pair<int, int>, pair<int, int> > > res;

bool next() {
//	cout << "next started " << lng << endl;
	bool flag = false;
	for (int i = lng - 1; i >= 0; i--)
		if (num[i] < good.size() - 1) {
			num[i]++;
			for (int j = i + 1; j < lng; j++)
				num[j] = 0;
			flag = true;
			break;
		}
	if (!flag) {
//		cout << "add" << endl;
		lng++;
		if (lng > 6)
			return false;
		for (int i = 0; i < lng; i++)
			num[i] = 0;
	}

	even.resize(lng * 2);
	for (int i = 0; i < lng; i++)
		even[i] = good[num[i]];
	for (int i = lng; i < 2 * lng; i++)
		even[i] = good[num[lng - (i - lng) - 1]];

//	cout << "odd_is_correct" << endl;

	odd.resize(lng * 2 - 1);
	for (int i = 0; i < lng; i++)
		odd[i] = good[num[i]];
	for (int i = lng; i < 2 * lng - 1; i++)
		odd[i] = good[num[lng - (i - lng) - 2]];

//	cout << "even_is_correct" << endl;

//	cout << "next finished" << endl;

	return true;
}

void check(vector<int> &a) {
//	cout << "check" << endl;
	for (int i = 0; i < good.size(); i++) {
		bool flag = false;
		for (int j = 0; j < a.size(); j++)
			if (a[j] == good[i]) {
				flag = true;
				break;
			}
		if (!flag)
			return;
	}
	int tmp1 = 0;
	for (int i = 0; i < a.size() && i < 4; i++) {
		tmp1 = 10 * tmp1 + a[i];
		if (tmp1 < 0 || tmp1 > 255)
			break;
		int tmp2 = 0;
		for (int j = i + 1; j < a.size() && j - i < 4; j++) {
			tmp2 = 10 * tmp2 + a[j];
			if (tmp2 < 0 || tmp2 > 255)
				break;
			int tmp3 = 0;
			for (int k = j + 1; k < a.size() - 1 && k - j < 4; k++) {
				tmp3 = 10 * tmp3 + a[k];
				if (tmp3 < 0 || tmp3 > 255)
					break;
				if (a.size() - k - 1 != 1 && a[a.size() - 1] == 0)
					continue;
				int tmp4 = 0;
				for (int r = k + 1; r < a.size() && r - k < 4; r++)
					tmp4 = 10 * tmp4 + a[r];
//
//				cout << "a" << tmp4 << " " << a.size() - j - endl;
				if (a.size() - k - 1 < 4 && tmp4 >= 0 && tmp4 < 256) {
//					cout << "b" << endl;
					res.push_back(make_pair(make_pair(tmp1, tmp2), make_pair(tmp3, tmp4)));
				}
				if (a[j + 1] == 0)
					break;
			}
			if (a[i + 1] == 0)
				break;
		}
		if (a[0] == 0)
			break;
	}
//	cout << "check finished" << endl;
}

int main() {
	int n;
	cin >> n;
	good.resize(n);

	for (int i = 0; i < n; i++)
		cin >> good[i];

	sort(good.begin(), good.end());

	while (next()) {
//		cout << lng << endl;
//		cout << "even" << endl;
		check(even);
//		cout << "odd" << endl;
		check(odd);
	}

//	cout << "done" << endl;

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i].first.first << "." << res[i].first.second << "." <<
			res[i].second.first << "." << res[i].second.second << endl;
}