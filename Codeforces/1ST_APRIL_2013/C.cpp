#include <iostream>

using namespace std;

int main() {
	int tux;
	cin >> tux;

	double foo = 0.0;
	double bar = 0.0;
	double baz = 0.0;
	double quz = 1.0;

	for (; tux != 0; tux--) {
		int pur;
		cin >> pur;
		foo = foo + pur;
		bar = bar + 1.0;
		if (foo * quz > bar * baz) {
			baz = foo;
			quz = bar;
		}
	}

	cout << baz / quz << endl;
}