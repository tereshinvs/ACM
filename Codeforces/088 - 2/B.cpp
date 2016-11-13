#include <iostream>
#include <stdio.h>

using namespace std;

int main()
	{
		int a, b, mod;
		cin >> a >> b >> mod;
		if (b >= mod) { cout << 2 << endl; return 0; }
		for (int i = 1; i < mod; i++)
			if (mod-((long long)i*1000000000)%mod > b)
				{
					cout << 1;
					return 0;
				}
		return 0;
	}