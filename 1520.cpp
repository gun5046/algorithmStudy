#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int n, m;
int arr[500][500];
int cnt = 0;

void move(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		cnt ++ ;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n && ny >= m) continue;
		if (arr[nx][ny] >= arr[x][y]) continue;
		move(nx, ny);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	move(0,0);
	cout << cnt;
}