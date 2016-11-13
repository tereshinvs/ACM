#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct node {
	char *tag;
};

node a[1000000];
int k = 0, last[1000000], ed[1000000], pr[1000000], ed_k = 0, prev_node[1000000], m, n;
char *req[1000000];
int kmp_res[1000000], res, tn;

void add_edge(int v1, int v2) {
	ed[ed_k] = v2;
	pr[ed_k] = last[v1];
	last[v1] = ed_k++;
	prev_node[v2] = v1;
}

char *next_token() {
	char c = getchar(), *nres = (char *)malloc(11);
	if (c == '\n') {
		nres[0] = 0;
		return nres;
	}

	int i;
	for (i = 0; (c = getchar()) != '>'; i++) {
		if (c == ' ' || c == '\n')
			break;
		nres[i] = c;
	}
	nres[i] = 0;

	return nres;
}

void read_node(char *_tag) {
	int cur_k = k;
	a[k++].tag = _tag;

	while (true) {
		char *s = next_token();
		if (!strlen(s))
			break;
		if (s[0] == '/')
			break;

		if (s[strlen(s) - 1] == '/') {
			add_edge(cur_k, k);
			s[strlen(s) - 1] = 0;
			a[k++].tag = s;
		} else {
			int temp_k = k;
			read_node(s);
			add_edge(cur_k, temp_k);
		}
	}
}

void dfs(int v) {
	req[tn] = a[v].tag;
	int j = kmp_res[tn - 1];
	while (j && strcmp(req[j], req[tn]) != 0)
		j = kmp_res[j - 1];
	if (!strcmp(req[j], req[tn]))
		kmp_res[tn] = j + 1;
	else
		kmp_res[tn] = 0;

	printf("dfs tn = %d    v = %d kmp_res[tn] = %d   req[tn] = %s\n", tn, v, kmp_res[tn], req[tn]);

	if (kmp_res[tn] >= n && last[v] != -1) {
//		for (int i = last[v]; i != -1; i = pr[i])
			printf("add to result\n");
			res++;
	}

	tn++;

	for (int i = last[v]; i != -1; i = pr[i])
		dfs(ed[i]);

	tn--;
}

int main() {
	for (int i = 0; i < 200; i++)
		req[i] = (char *)malloc(11);

	for (int i = 0; i < 1000000; i++)
		pr[i] = last[i] = prev_node[i] = -1;

	char *ts = (char *)malloc(11);
	ts[0] = 0;
	read_node(ts);


/*	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%d tag: %s\n", prev_node[i], a[i].tag);
		for (int j = last[i]; j != -1; j = pr[j])
			printf("(%d %d)", ed[j], pr[j]);
//		printf("\n");
	}*/

	scanf("%d", &m);
	while (getchar() != '\n');
	for (int q = 0; q < m; q++) {
		char *sy = next_token();
		printf("sy = #%s#\n", sy);
		for (n = 0; strlen(sy); n++) {
			req[n] = sy + 1;
			sy = next_token();
		}

		printf("reading is ok, n = %d\n", n);
		for (int i = 0; i < n; i++)
			printf("!%d #%s#\n", i, req[i]);

		kmp_res[0] = 0;
		for (int i = 1; i < n; i++) {
			int j = kmp_res[i - 1];
			while (j && strcmp(req[j], req[i]))
				j = kmp_res[j - 1];
			if (!strcmp(req[j], req[i]))
				kmp_res[i] = j + 1;
			else
				kmp_res[i] = 0;
		}

		tn = n;
		res = 0;

		printf("start dfs\n");
		dfs(0);

		printf("%d\n", res);
	}

	return 0;
}