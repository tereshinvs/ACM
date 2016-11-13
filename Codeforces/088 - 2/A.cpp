#include <stdio.h>

using namespace std;

int main()
	{
		int n, m, st, fn, tim, tim1;
		scanf("%d%d", &n, &m); m--;
		for (int i = 0; i < n; i++)
			{
				scanf("%d%d%d", &st, &fn, &tim); st--; fn--;
				if (st == fn) { printf("%d\n", tim); continue; }
				if (st < fn)
					{
						tim1 = tim % (2*m);
						if (tim1 > st) printf("%d\n", tim + (2*m-tim1) + fn);
									else printf("%d\n", tim + (st-tim1) + fn - st);
					}
				else {
						tim1 = tim % (2*m);
						if (tim1 <= m + (m-st)) printf("%d\n", tim + (m + (m-st) - tim1) + st - fn);
													else printf("%d\n", tim + (2*m-tim1) + m + (m-st) + st - fn);
					}
			}
		return 0;
	}