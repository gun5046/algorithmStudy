#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 999999999
using namespace std;

int n, m;
int arr[1001][1001];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int visit[1001][1001][2];
priority_queue<int>pq;
/*void move(int x ,int y, bool f, int c) {
	if (x == n && y == m) {
		pq.push(-c);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <1 || ny <1 || nx>n || ny >m) continue;
		
		if (visit[nx][ny] >= visit[x][y] + 1) continue;
		if (arr[nx][ny] == 1) {
			if (f) continue;
			move(nx, ny, !f, c + 1);
		}
		else {
			move(nx, ny, f, c + 1);
		}
	}
}
*/
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1]-'0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 2; k++) {
				visit[i][j][k] = MAX;
			}
		}
	}

	//move(1,1, 0, 1);
	queue<pair<bool, pair<int, int>>>q;
	
	q.push({ 0,{1,1} });
	visit[1][1][0] = 1;
	
	while (!q.empty()) {
		bool f = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			bool nf= f;
	
			if (nx <1 || ny <1 || nx>n || ny > m) continue;
			if (arr[nx][ny] == 1) {
				
				if (f) continue;
				if (visit[nx][ny][!nf] <= visit[x][y][nf] + 1) continue;
				visit[nx][ny][!nf] = visit[x][y][nf] + 1;
				nf = true;
			}
			else {
				
				if (visit[nx][ny][nf] <= visit[x][y][nf] + 1) continue;
				visit[nx][ny][nf] = visit[x][y][nf] + 1;
			}

			q.push({ nf, {nx,ny} });
		}
	}
	
	if (visit[n][m][0] == MAX && visit[n][m][1] == MAX) {
		cout << -1;
	}
	else {
		cout << min(visit[n][m][0], visit[n][m][1]);


	}
}