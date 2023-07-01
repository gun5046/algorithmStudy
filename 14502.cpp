#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int map[9][9];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int wall=0;
int virus(int x1, int y1, int x2, int y2, int x3, int y3) {
	bool visited[9][9] = { false, };
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 2 && visited[i][j]==false) {
				queue<pair<int,int>>q;
				q.push({ i,j });
				visited[i][j] = true;
				while (!q.empty()) {
					cnt++;
					int x = q.front().first;
					int y = q.front().second;
					
					q.pop();
					for (int d = 0; d < 4; d++) {
						int nx = dx[d] + x;
						int ny = dy[d] + y;
						if (nx<1 || nx > n || ny <1 || ny>m) continue;
						if (map[nx][ny] == 1) continue;
						if (visited[nx][ny]) continue;
						visited[nx][ny] = true;
						q.push({nx, ny});
					}
				}
			}
		}
	}


	return (n*m) -wall -3 - cnt;
}


int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {	
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				wall++;
			}
		}
	}
	priority_queue <int> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				for (int a = 1; a <= n; a++) {
					for (int b = 1; b <= m; b++) {
						if (map[a][b] == 0) {
							map[a][b] = 1;
							for (int x = 1; x <= n; x++) {
								for (int y = 1; y <= m; y++) {
									if (map[x][y] == 0) {
										map[x][y] = 1;
										pq.push(virus(i, j, a, b, x, y));
										map[x][y] = 0;
									}
								}
							}
							map[a][b] = 0;
						}
					}
				}
				map[i][j] = 0;
			}
		}
	}

	cout << pq.top();
}
