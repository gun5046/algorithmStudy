#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
int arr[50][50];
queue<pair<int,int>>q;
int visit[50][50];
int dx[4] = {0,1,-1,0};
int dy[4] = { 1,0,0,-1 };
priority_queue<int> pq;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j]-'0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 99999;
		}
	}

	q.push({ 0,0  });
	visit[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] == 0) {
				if (visit[nx][ny] <= visit[x][y] + 1) continue;
				visit[nx][ny] = visit[x][y] + 1;
				q.push({ nx, ny });
			}
			else {
				if (visit[nx][ny] <= visit[x][y]) continue;
				visit[nx][ny] = visit[x][y];
				q.push({ nx,ny });
			}
			
		}
	}

	cout << visit[n-1][n-1];
}