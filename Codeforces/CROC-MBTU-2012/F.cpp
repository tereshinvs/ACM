#include <cstdio>
#include <ctime>

using namespace std;

time_t rawtime;
struct tm *tstr;

int get_utc(int year, int month, int day, int hour, int minute, int second) {
    tstr->tm_year = year - 1900;
    tstr->tm_mon = month - 1;
    tstr->tm_mday = day;
    tstr->tm_hour = hour;
    tstr->tm_min = minute;
    tstr->tm_sec = second;
    tstr->tm_isdst = -1;

    return mktime(tstr);
}

char ts[1000000];

int main() {
    time(&rawtime);
    tstr = localtime(&rawtime);

	int n, m;
	scanf("%d%d", &n, &m);

	int a[10000];
	char s[10000][30];
	int N = 0, month, day, hour, minute, second;
/*	while (scanf("2012-%d-%d %d:%d:%d", &month, &day, &hour, &minute, &second) != EOF) {
		sprintf(s[N], "2012-%.2d-%.2d %.2d:%.2d:%.2d", month, day, hour, minute, second);
		a[N++] = get_utc(2012, month, day, hour, minute, second);

		while (!feof(stdin) && getchar() != '\n');
	}*/
	while (!feof(stdin)) {
		fgets(s[N], 30, stdin);
		while (!feof(stdin) && getchar() != '\n');
	//	printf("%s\n", s[N]);
		sscanf(s[N], "2012-%d-%d %d:%d:%d", &month, &day, &hour, &minute, &second);
		s[N][19] = 0;
	//	printf("%s\n", s[N]);
		a[N++] = get_utc(2012, month, day, hour, minute, second);
	}

	int left = 0;
	for (int i = 0; i < N; i++) {
	//	printf("%d %d\n", i, a[i]);
		while (left < i && a[left] + n - 1 < a[i])
			left++;

		if (i - left + 1 >= m) {
			printf("%s\n", s[i]);
			return 0;
		}
	}

	printf("-1\n");
}