#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>
using namespace std;

void panda();
void move(int x, int y, int total);
int n;
int map[500][500];
int dp[500][500][4];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

priority_queue<int>pq;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int k = 0; k < n; k++) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < 4; b++) {
				dp[k][a][b] = 0;
			}
		}
	}
	panda();
	cout << pq.top();
}

void panda() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			move(i, j, 0);
		}
	}
}

void move(int x, int y, int total) {
	bool flag= false;
	for (int k = 0; k < 4; k++) {
		int nx = dx[k] + x;
		int ny = dy[k] + y;

		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) continue;
		if (map[nx][ny] <= map[x][y]) continue;

		if (dp[nx][ny][k] > dp[x][y][k] + map[x][y]) continue;

		flag = true;
		dp[nx][ny][k] = dp[x][y][k] + total;
		move(nx, ny, total + map[nx][ny]);
	}
	if (!flag) {
		pq.push(total);
	}
}