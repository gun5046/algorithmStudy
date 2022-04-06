#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>
#include <cstring>
using namespace std;

void panda();
int move(int x, int y);
int n;
int map[500][500];
int dp[500][500];
int maximum = 1;
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = 0;
		}
	}

	
	panda();
	cout << maximum;
}



void panda() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maximum = max(maximum, move(i,j));
		}
	}
}

int move(int x, int y) {
	if (dp[x][y] == 0) {
		dp[x][y] = 1;
		int t = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			
			if (nx<0 || ny<0 || nx>n - 1 || ny > n - 1) continue;
			if (map[nx][ny] <= map[x][y]) continue;
			
			t = max(t,move(nx, ny));
		}
		dp[x][y] += t;
	}


	return dp[x][y];
}



/*
void panda() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool flag= false;
			if (dp[i][j] != 1) continue;
			
			for (int k = 0; k < 4; k++) {
				
				int nx = i + dx[k]; int ny = i + dy[k];
				
				if (nx <0 || ny <0 || nx >n - 1 || ny > n - 1) continue;
				if (map[nx][ny] < map[i][j]) {
					flag = true;
					break;
				}
			}
			if (flag) continue;
			move(i, j);
		}
	}
}

void move(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx <0 || ny <0 || nx >n - 1 || ny > n - 1) continue;
		if (map[nx][ny] <= map[x][y]) continue;
		if (dp[nx][ny] >= dp[x][y] + 1) continue;

		dp[nx][ny] = dp[x][y] + 1;
		move(nx, ny);
	}
	maximum = max(maximum, dp[x][y]);
}
*/