#include <stdio.h>

using namespace std;

char s[100000];
int n = 0;

int main() {
	while ((c = getchar()) != '\n')
		s[n++] = c;
	int one = 0, zero = 0, qst = 0, masha = (n - 2) / 2 + (n % 2 ? 1 : 0), pit = (n - 2) / 2;
	for (int i = 0; i < n; i++)
		switch (s[i]) {
			case '1': one++;
			case '0': zero++;
			case '?': qst++;
		}
	if (masha + 1 < one) {
		printf("11\n");
		return 0;
	}
	if (pit + 1 < zero) {
		printf("00\n");
		return 0;
	}

	int z = 0, o = 0, t = 0, f = 0;
	if (masha + 1 < one + qst || pit >= zero)
		f = 1;
	if (pit + 1 < zero + qst || masha >= one)
		z = 1;

	for (int i = 0; i <= qst; i++)
		if (masha < one + i && pit < zero + qst - i) {
			
		}


	if (masha + 1 < one + qst && (s[n - 1] == '1' || s[n - 1] == '?'))
		o = 1;
	if (pit + 1 < one + qst && (s[n - 1] == '1' || s[n - 1] == '?'))
		o = 1;*/
	return 0;
}