
/*
* 
5
20 3
2 2 3 2 2 2 2 3 3 4 4 3 2 2 3 3 3 2 2 3
4 4 1 4 4 1 4 4 1 1 1 4 1 4 3 3 3 3 3 3
4 4 1 100
7 10 3 40
6 3 2 70
40 2
0 3 0 3 3 2 2 1 0 4 1 3 3 3 0 3 4 1 1 3 2 2 2 2 2 0 2 3 2 2 3 4 4 3 3 3 2 0 4 4
0 1 0 3 4 0 4 0 0 1 1 1 0 1 4 4 4 4 4 3 3 3 0 1 0 4 3 2 1 4 4 3 2 3 2 2 0 4 2 1
5 2 4 140
8 3 3 490
60 4
0 3 3 3 0 1 2 2 2 1 2 2 3 3 4 4 0 3 0 1 1 2 2 3 2 2 3 2 2 0 3 0 1 1 1 4 1 2 3 3 3 3 3 1 1 4 3 2 0 4 4 4 3 4 0 3 3 0 3 4
1 1 4 1 1 1 1 1 1 4 4 1 2 2 3 2 4 0 0 0 4 3 3 4 3 3 0 1 0 4 3 0 4 3 2 3 2 1 2 2 3 4 0 2 2 1 0 0 1 3 3 1 4 4 3 0 1 1 1 1
6 9 1 180
9 3 4 260
1 4 1 500
1 3 1 230
80 7
2 2 2 2 2 2 0 2 2 0 4 0 2 3 3 2 3 3 0 3 3 3 4 3 3 2 1 1 1 0 4 4 4 1 0 2 2 2 1 1 4 1 2 3 4 4 3 0 1 1 0 3 4 0 1 2 2 2 1 1 3 4 4 4 4 4 4 3 2 1 4 4 4 4 3 3 3 0 3 3
4 4 1 1 2 1 2 3 3 3 4 4 4 4 4 1 1 1 1 1 1 1 1 0 3 3 2 0 4 0 1 3 3 3 2 2 1 0 3 2 3 4 1 0 1 2 2 3 2 0 4 0 3 4 1 1 0 0 3 2 0 0 4 3 3 4 0 4 4 4 4 0 3 0 1 1 4 4 3 0
4 3 1 170
10 1 3 240
10 5 3 360
10 9 3 350
9 6 2 10
5 1 4 350
1 8 2 450
100 8
2 2 3 2 0 2 0 3 3 1 2 2 2 2 3 3 0 4 4 3 2 3 4 3 3 2 3 4 4 4 2 2 2 0 2 2 4 4 4 4 1 1 1 2 2 2 4 3 0 2 3 3 4 0 0 1 1 4 1 1 1 1 2 2 1 1 3 3 3 0 3 2 3 3 0 1 3 3 0 1 1 3 3 4 0 4 1 1 2 2 4 0 4 1 1 2 2 1 1 1
4 4 4 0 4 1 1 4 1 1 1 1 3 2 1 2 1 1 4 4 1 0 2 3 4 4 4 4 4 0 1 0 2 2 2 0 2 2 2 2 2 2 3 0 0 1 4 3 3 2 0 0 4 4 4 0 2 0 4 1 1 2 2 0 4 4 0 0 2 0 2 3 3 0 2 3 0 3 4 0 4 3 4 4 3 4 1 1 2 2 2 0 0 1 0 4 1 1 1 4
3 4 2 340
10 1 1 430
3 10 4 10
6 3 4 400
7 4 1 80
4 5 1 420
4 1 2 350
8 4 4 300
*/

#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <cstring>
#include <string>
#include <stack>
#include <list>

using namespace std;

class Charge {
public:
	int x;
	int y;
	int power;
	int range;
	bool status = false;
};
int m;
int a;
int x[2];
int y[2];

vector<int>mv[2];
vector<Charge> c;
int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, -1, 0, 1, 0 };
vector<int>map1[11][11];
int max_charge = 0;
void use(int idx) {
	if (c[idx].status) {
		cout << "¹Ý°¥" << "\n";
	}
	else {
		max_charge += c[idx].power;
		cout << "add_charge : " << c[idx].power<<"\n";
	}

	c[idx].status = true;
}

void sol() {
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < a; j++) {
			c[j].status = false;
		}
		cout << "move :" << i <<"\n";

		x[0] = x[0] + dx[mv[0][i]];
		y[0] = y[0] + dy[mv[0][i]];
		x[1] = x[1] + dx[mv[1][i]];
		y[1] = y[1] + dy[mv[1][i]];
		cout << "j : " << 0 << " " << x[0] << " " << y[0] << "\n";
		cout << "j : " << 1 << " " << x[1] << " " << y[1] << "\n";
		if (map1[y[0]][x[0]].size() <= map1[y[1]][x[1]].size()) {
			for (int k = map1[y[0]][x[0]].size() - 1; k >= 0; k--) {
				int idx = map1[y[0]][x[0]][k];
				if (c[idx].status) continue;
				cout << "add charge0 : " << c[idx].power << "\n";
				max_charge += c[idx].power;
				c[idx].status = true;
				break;
			}
			for (int k = map1[y[1]][x[1]].size() - 1; k >= 0; k--) {
				int idx = map1[y[1]][x[1]][k];
				if (c[idx].status) continue;
				cout << "add charge1 : " << c[idx].power << "\n";
				max_charge += c[idx].power;
				c[idx].status = true;
				break;
			}
		}
		else {
			for (int k = map1[y[1]][x[1]].size() - 1; k >= 0; k--) {
				int idx = map1[y[1]][x[1]][k];
				if (c[idx].status) continue;
				cout << "add charge1 : " << c[idx].power << "\n";
				max_charge += c[idx].power;
				c[idx].status = true;
				break;
			}
			for (int k = map1[y[0]][x[0]].size() - 1; k >= 0; k--) {
				int idx = map1[y[0]][x[0]][k];
				if (c[idx].status) continue;
				cout << "add charge0 : " << c[idx].power << "\n";
				max_charge += c[idx].power;
				c[idx].status = true;
				break;
			}
		}
		for (int j = 1; j < 11; j++) {
			for (int k = 1; k < 11; k++) {
				cout << map1[j][k].size() << " ";
			}
			cout << "\n";
		}
	}
	
	
}
void setBoundary() {
	for (int i = 0; i < a; i++) {
		int x = c[i].x;
		int y = c[i].y;
		queue<pair<int, pair<int, int>>>q;
		bool visit[11][11];
		memset(visit, 0, sizeof(visit));
		q.push({ 0,{ y,x } });
		visit[y][x] = true;
		while (!q.empty()) {
			y = q.front().second.first;
			x = q.front().second.second;
			int r = q.front().first;
			q.pop();

			for (int j = 0; j <= 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 1 || ny < 1 || nx>10 || ny>10) continue;
				if (visit[ny][nx]) continue;
				if (r + 1 > c[i].range) continue;
				visit[ny][nx] = true;
				map1[ny][nx].push_back(i);
				q.push({ r + 1, {ny, nx} });


			}
		}
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= 10; k++) {
				cout << map1[j][k].size() << " ";
			}
			cout << "\n";
		}
		cout << "\n\n\n";
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			sort(map1[i][j].begin(),map1[i][j].end());
		}
	}
}
bool compare(Charge c1, Charge c2) {
	if (c1.power > c2.power) {
		return false;
	}
	else if (c1.power == c2.power) {
		if (c1.x > c2.x) {
			return false;
		}
		else if (c1.x == c2.x) {
			if (c1.y >= c2.y) {
				return false;
			}
			return true;
		}
		return true;
	}
	return true;
}


int main() {
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		cin >> m >> a;
		x[0] = 1; y[0] = 1; x[1] = 10; y[1] = 10;
		c.clear();
		max_charge = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				map1[i][j].clear();
			}
		}
		for (int i = 0; i < 2; i++) {
			mv[i].clear();
		}
		for (int i = 0; i < 2; i++) {
			mv[i].push_back(0);
			for (int j = 0; j < m; j++) {
				int n;
				cin >> n;
				mv[i].push_back(n);
			}
		}

		for (int i = 0; i < a; i++) {
			int n1, n2, n3, n4;
			Charge c1;
			cin >> n1 >> n2 >> n3 >> n4;
			c1.x = n1;
			c1.y = n2;
			c1.range = n3;
			c1.power = n4;
			c.push_back(c1);
		}
		sort(c.begin(), c.end(), compare);
		for (int i = 0; i < a; i++) {
			map1[c[i].y][c[i].x].push_back(i);
		}
		setBoundary();


		sol();
		cout << "#" << t << " " << max_charge << "\n";
	}
}