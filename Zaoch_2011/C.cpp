#include <iostream>

using namespace std;

int get_kth_digit_in_number(long long n, long long k) {
	int dgts[10] = {0}, i;
	for (i = 0; n; i++, n /= 10)
		dgts[i] = n % 10;
	return dgts[i - k];
}

long long get_dig_amount(long long n) {           
	if (!n)
		return 1;
	int res = 0;
	while (n)
		res++, n /= 10;
	return res;
}

long long seq_len[52];

int get_kth_digit(long long n, long long k) {
	if (n == 1 && k == 1)
		return 1;
	if (n == 1 && k != 1)
		return -1;
	if (k <= get_dig_amount(n))
		return get_kth_digit_in_number(n, k);
	if (n <= 51) {
		if (k > seq_len[n])
			return -1;
		if (k <= get_dig_amount(n) + seq_len[n - 1])
			return get_kth_digit(n - 1, k - get_dig_amount(n));
		else
			return get_kth_digit(n - 1, k - get_dig_amount(n) - seq_len[n - 1]);
	} else
		return get_kth_digit(n - 1, k - get_dig_amount(n));
}

int main() {
	seq_len[0] = 0;
	for (int i = 1; i <= 51; i++)
		seq_len[i] = seq_len[i - 1] * 2 + get_dig_amount(i);
	long long n, k;
	cin >> n >> k;
	cout << get_kth_digit(n, k) << endl;
}