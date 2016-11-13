#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct Attack {
	int day;
	int s;
	int w, e;

	Attack(int _day, int _s, int _w, int _e):
		day(_day), s(_s), w(_w), e(_e) {}

	bool operator <(const Attack &t) const {
		return day < t.day;
	}
};

int t[20000000] = {0};

void push (int v) {
	if (t[v] != -1) {
		t[v*2] = t[v*2+1] = t[v];
		t[v] = -1;
	}
}

void construct() {
	for (int i = 0; i < 20000000; i++)
		t[i] = 0;
}
 
void update (int v, int tl, int tr, int l, int r, int color) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] = color;
	else {
		push (v);
		int tm = (tl + tr) / 2;
		update(v*2, tl, tm, l, min(r,tm), color);
		update(v*2+1, tm+1, tr, max(l,tm+1), r, color);
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}
 
int minimum(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return INF;
	if (tl == l && tr == r)
		return t[v];
	push(v);
	int tm = (tl + tr) / 2;
	return min(minimum(v * 2, tl, tm, l, min(r, tm)),
		minimum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int q = 0; q < t; q++) {
		vector<Attack> att;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
			cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;

			for (int j = 0; j < ni; j++)
				att.push_back(Attack(di + j * delta_di, si + j * delta_si,
					wi + j * delta_pi, ei + j * delta_pi));
		}

		sort(att.begin(), att.end());

		construct();

		int res = 0;
		list<pair<int, int> > lst;
		list<int> lst_s;
		for (int i = 0; i < att.size(); i++) {
			int tmp = minimum(1, -1000000, 1000000, att[i].w, att[i].e);
			if (tmp < att[i].s)
				res++;
			lst.push_back(make_pair(att[i].w, att[i].e));
			lst_s.push_back(att[i].s);

			if (i < att.size() - 1 && att[i].day < att[i + 1].day) {
				int y = lst.size();
				for (int i = 0; i < y; i++) {
					auto w = lst.front(); lst.pop_front();
					int w1 = lst_s.front(); lst_s.pop_front();
					update(1, -1000000, 1000000, w.first, w.second, w1);
				}
			}
		}
	}
}