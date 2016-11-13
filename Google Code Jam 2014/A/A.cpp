#include <iostream>
#include <set>

std::set<int> read_set() {
	int n;
	std::cin >> n;
	int a[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			std::cin >> a[4][4];
	return std::set<int>(a[n - 1], a[n - 1] + 4);
}

int main() {
	int t;
	std::cin >> t;
	for (int q = 0; q < t; q++) {
		std::set<int> tmp = read_set();
		std::set<int> res = read_set();
		res.insert(tmp.begin(), tmp.end());
		std::cout << "Case #" << q + 1 << ": ";
		switch (res.size()) {
			case 0: std::cout << "Volunteer cheated!"; break;
			case 1: std::cout << *res.begin(); break;
			default: std::cout << "Bad magician!" << " " << res.size(); break;
		}
		std::cout << std::endl;
	}
}