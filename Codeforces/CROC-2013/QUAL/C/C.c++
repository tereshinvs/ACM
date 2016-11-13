#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool test(vector<unsigned> &data, unsigned i, int k) {
	set<unsigned> tmp;
	for (auto it: data)
		tmp.insert(it & i);
	return tmp.size() == k;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<unsigned> data;
	for (int i = 0; i < n; i++) {
		unsigned x1, x2, x3, x4;
		char c;
		cin >> x1 >> c >> x2 >> c >> x3 >> c >> x4;
		data.push_back((x1 << 24) + (x2 << 16) + (x3 << 8) + x4);
	}
	unsigned res = 2;
	for (unsigned i = ~0 - 1; i != 0; i <<= 1)
		if (test(data, i, k))
			res = i;

	if (res == 2)
		cout << -1;
	else {
		unsigned tmp[4];
		for (int i = 0; i < 4; i++, res /= 256)
			tmp[3 - i] = res % 256;
		for (int i = 0; i < 4; i++) {
			cout << tmp[i];
			if (i != 3)
				cout << ".";
		}
	}
	cout << endl;
}