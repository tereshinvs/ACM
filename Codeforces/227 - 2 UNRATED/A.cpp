#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int h1, m1, h2, m2;
	scanf("%d:%d\n%d:%d", &h1, &m1, &h2, &m2);
	int t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
	int t = t1 - t2;
	if (t < 0)
		t += 24 * 60;
	cout << setfill('0') << setw(2) << t / 60 << ":" << setfill('0') << setw(2) << t % 60 << endl;
	return 0;
}