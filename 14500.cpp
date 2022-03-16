#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
#include <utility>
using namespace std;

int n, m;
int map[501][501];
bool visited[501][501] = {false, };
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
priority_queue<int> pq;

void tetromino(int x, int y, int sum,int cnt) {
	visited[x][y] = true;
	if (cnt == 3) {
		pq.push(sum);
		
	}
	else {

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i]; int new_y = y + dy[i];

			if (new_x<1 || new_y<1 || new_x>n || new_y >m) continue;
			if (visited[new_x][new_y]) continue;

			tetromino(new_x, new_y, sum + map[new_x][new_y], cnt + 1);
			visited[new_x][new_y] = false;
		}
	}
}
void exceptionCase(int x, int y) {
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 1 || x + dx[i] > n || y + dy[i] <1 || y + dy[i]>m) continue;
		for (int j = i + 1; j < 4; j++) {
			if (x + dx[j] < 1 || x + dx[j] > n || y + dy[j] <1 || y + dy[j]>m) continue;
			for (int k = j + 1; k < 4; k++) {
				if (x + dx[k] < 1 || x + dx[k] > n || y + dy[k] <1 || y + dy[k]>m) continue;
				pq.push((map[x][y]+map[x+dx[i]][y+dy[i]] + map[x+dx[j]][y+dy[j]] + map[x+ dx[k]][y+dy[k]]));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i + 1][j + 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tetromino(i,j,map[i][j], 0);
			exceptionCase(i,j);
			for (int k = i; k < i + 5; k++) {
				for (int l = j; l < j + 5; l++) {
					visited[k][l] = false;
				}
			}
		}
	}
	cout << pq.top();
}