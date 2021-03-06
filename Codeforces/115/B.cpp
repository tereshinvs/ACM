#include <stdio.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map< string, int > a;

int main() {
	int n, rs;
	string nm;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nm >> rs;
		a[nm] = max(a[nm], rs);
	}
	cout << a.size() << endl;
	n = a.size();
	map< string, int >::iterator it1, it2;
	for (it1 = a.begin(); it1 != a.end(); it1++) {
		int le = 0, g = 0;                      
		for (it2 = a.begin(); it2 != a.end(); it2++) {
			if (it2->second > it1->second)
				g++;
			if (it2->second <= it1->second)
				le++;
		}
		cout << it1->first << " ";
		if (2 * g > n)
			cout << "noob";
		if (2 * le >= n && 5 * g > n)
			cout << "random";
		if (10 * le >= 8 * n && 10 * g > n)
			cout << "average";	
		if (10 * le >= 9 * n && 100 * g > n)
			cout << "hardcore";	
		if (100 * le >= 99 * n)
			cout << "pro";	
		cout << endl;
	}
	return 0;
}