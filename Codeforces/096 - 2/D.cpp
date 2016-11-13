#include <stdio.h>

struct point {
	int x, y;
};

struct next_str {
	point ru, rd, ul, ur, lu, ld, dr, dl;
};

char a[50][50];
int m, n, st, dp = 1, cp = 0;
next_str next[50][50];

int get_move_x(int p) {
	switch (p) {
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 0;
		case 3:
			return -1;
		default:
			return 50;
	}
}

int get_move_y(int p) {
	switch (p) {
		case 0:
			return -1;
		case 1:
			return 0;
		case 2:
			return 1;
		case 3:
			return 0;
		default:
			return 50;
	}
}

point find_next(int x, int y, int dp, int cp) {
	int tx = get_move_x(dp), ty = get_move_y(dp);
	while (x + tx < n && y + ty < m
			&& x + tx >= 0 && y + ty >= 0
			&& a[x][y] == a[x + tx][y + ty]) {
		x += tx;
		y += ty;
	}
	tx = get_move_x(cp); ty = get_move_y(cp);
	while (x + tx < n && y + ty < m
			&& x + tx >= 0 && y + ty >= 0
			&& a[x][y] == a[x + tx][y + ty]) {
		x += tx;
		y += ty;
	}
	point res; res.x = x; res.y = y;
	return res;
}

void update_next(int x, int y) {
	next[x][y].ru = find_next(x, y, 1, 0);
	next[x][y].rd = find_next(x, y, 1, 2);
	next[x][y].ul = find_next(x, y, 0, 3);
	next[x][y].ur = find_next(x, y, 0, 1);
	next[x][y].lu = find_next(x, y, 3, 0);
	next[x][y].ld = find_next(x, y, 3, 2);
	next[x][y].dr = find_next(x, y, 2, 1);
	next[x][y].dl = find_next(x, y, 2, 3);
}

point get_temp(point bp, int dp, int cp) {
	if (dp == 0)
		return cp == 3 ? next[bp.x][bp.y].ul : next[bp.x][bp.y].ur;
	if (dp == 1)
		return cp == 0 ? next[bp.x][bp.y].ru : next[bp.x][bp.y].rd;
	if (dp == 2)
		return cp == 3 ? next[bp.x][bp.y].dl : next[bp.x][bp.y].dr;
	if (dp == 3)
		return cp == 0 ? next[bp.x][bp.y].lu : next[bp.x][bp.y].ld;
	point res; res.x = 0; res.y = 0;
	return res;
}

void update_dp_cp() {
	int temp;
	if (dp == 0) {
		if (cp == 3)
			cp = 1;
		else { temp = dp; dp = cp; cp = temp; }
		return;
	}
	if (dp == 1) {
		if (cp == 0)
			cp = 2;
		else { temp = dp; dp = cp; cp = temp; }
		return;
	}
	if (dp == 2) {
		if (cp == 1)
			cp = 3;
		else { temp = dp; dp = cp; cp = temp; }
		return;
	}
	if (dp == 3) {
		if (cp == 2)
			cp = 0;
		else { temp = dp; dp = cp; cp = temp; }
		return;
	}
}

int main() {
	scanf("%d%d\n", &m, &st);
	char c;
	for (int i = 0; i < m; i++) {
		n = 0;
		while ((c = getchar()) != '\n')
			a[n++][i] = c;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] > '0')
				update_next(i, j);
	point temp, bp; bp.x = 0; bp.y = 0;
	for (int i = 0; i < st; i++) {
		temp = get_temp(bp, dp, cp);
		if (temp.x + get_move_x(dp) < n && temp.y + get_move_y(dp) < m
			&& temp.x + get_move_x(dp) >= 0 && temp.y + get_move_y(dp) >= 0
			&& a[temp.x + get_move_x(dp)][temp.y + get_move_y(dp)] != '0') {
			bp.x = temp.x + get_move_x(dp);
			bp.y = temp.y + get_move_y(dp);
		} else
			update_dp_cp();
	}
	printf("%c\n", a[bp.x][bp.y]);
	return 0;
}