#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int map[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0,0 };
int visited[100][100];
int n;
int road[100][100];
void bfs() {

	queue<pair<int,int>>q;
	q.push({ 0,0 });
	visited[0][0];
	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx > n - 1 || ny > n - 1 || nx < 0 || ny < 0) continue;
			if (visited[nx][ny]) {
				if (road[nx][ny] <= map[nx][ny] + road[x][y]) continue;
			}
			road[nx][ny] = road[x][y] + map[nx][ny];
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

}

int main() {
	int t;

	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		
		cin >> n;

		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < n; j++) {
				map[i][j] = str[j] - '0';
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				visited[i][j] = false;
				road[i][j] = 0;
			}
		}
		bfs();
		cout << "#" <<test_case<< " " << road[n - 1][n - 1] << "\n";

	}
}