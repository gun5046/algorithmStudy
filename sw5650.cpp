#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n;
int arr[100][100];
pair<int, int> start;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;
int nd, nx, ny;
vector<pair<int, int>>hole[11];
int turnback(int d) {
	switch (d) {
	case 0:
		return 1;
		break;
	case 1:
		return 0;
		break;
	case 2:
		return 3;
		break;
	case 3:
		return 2;
		break;
	}
}

int block(int d, int b) {


	switch (b) {
	case 5:
		return turnback(d);
		break;
	case 1:
		switch (d) {
		case 0:
			return turnback(d);
			break;
		case 1:
			return 3;
			break;
		case 2:
			return 0;
			break;
		case 3:
			return turnback(d);
			break;
		}
		break;
	case 2:
		switch (d) {
		case 0:
			return 3;
			break;
		case 1:
			return turnback(d);
			break;
		case 2:
			return 1;
			break;
		case 3:
			return turnback(d);
			break;
		}
		break;
	case 3:
		switch (d) {
		case 0:
			return 2;
			break;
		case 1:
			return turnback(d);
			break;
		case 2:
			return turnback(d);
			break;
		case 3:
			return 1;
			break;
		}
		break;
	case 4:
		switch (d) {
		case 0:
			return turnback(d);
			break;
		case 1:
			return 2;
			break;
		case 2:
			return turnback(d);
			break;
		case 3:
			return 0;
			break;
		}
		break;
	}
}

void move(int x, int y, int d, int wall) {

	if (x == start.first && y == start.second) {

		//cout << "시작지점 끝"<<"\n";
		if (ans < wall) {
			ans = wall;
		}
		return;
	}
	//cout << "x : "<<x << " y : "<<y << " d : "<<d << "\n";

	if (x < 0 || y < 0 || x >= n || y >= n) {
		nd = turnback(d);
		nx = x + dx[nd];
		ny = y + dy[nd];
		//if (visit[nx][ny][nd] > visit[x][y][d] + 1) return;
		//visit[nx][ny][nd] = visit[x][y][d] + 1;
		move(nx, ny, nd, wall + 1);
		return;
	}

	if (1 <= arr[x][y] && arr[x][y] <= 5) {
		nd = block(d, arr[x][y]);
		nx = x + dx[nd];
		ny = y + dy[nd];
		//if (visit[nx][ny][nd] > visit[x][y][d] + 1) return;
		//visit[nx][ny][nd] = visit[x][y][d] + 1;
		move(nx, ny, nd, wall + 1);
		return;
	}

	if (arr[x][y] == -1) {
		//cout << "블랙홀 끝"<<"\n";
		if (ans < wall) {
			ans = wall;
		}
		return;
	}
	if (6 <= arr[x][y] && arr[x][y] <= 10) {

		if (hole[arr[x][y]][0] == make_pair(x, y)) {
			nx = hole[arr[x][y]][1].first + dx[d];
			ny = hole[arr[x][y]][1].second + dy[d];
			nd = d;
		}
		else {
			nx = hole[arr[x][y]][0].first + dx[d];
			ny = hole[arr[x][y]][0].second + dy[d];
			nd = d;

		}
		//if (visit[nx][ny][nd] > visit[x][y][d] + 1) return;
		//visit[nx][ny][nd] = visit[x][y][d] + 1;
		move(nx, ny, nd, wall);
		return;

	}

	nx = x + dx[d];
	ny = y + dy[d];
	nd = d;
	//if (visit[nx][ny][nd] > visit[x][y][d] + 1) return;
	//visit[nx][ny][nd] = visit[x][y][d] + 1;
	move(nx, ny, nd, wall);
	return;
}

void sol() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) continue;
			start = { i,j };
			for (int k = 0; k < 4; k++) {
				move(i + dx[k], j + dy[k], k, 0);
			}

		}
	}
}


int main() {
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		cin >> n;
		for (int i = 0; i < 11; i++) {
			hole[i].clear();
		}
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] >= 6 && arr[i][j] <= 10) {
					hole[arr[i][j]].push_back(make_pair(i, j));
				}
			}
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 4; k++) {
					visit[i][j][k] = 0;

				}
			}
		}*/
		sol();
		cout << "#" << t << " " << ans << "\n";
	}
}