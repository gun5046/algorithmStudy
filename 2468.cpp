#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <cstring>
using namespace std;

int n;
int box[101][101];
int cnt=0;
int maximum = -1;
queue<pair<int,int>> q;
set<int>s;
set<int>::iterator iter;

bool visited[101][101] = { false, };

void findArea() {
	for (iter = s.begin(); iter != s.end(); iter++) {
		cnt = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					q.push({ i,j });
					if (box[i][j] <= *iter || visited[i][j]) {
						q.pop();
						continue;
					}
					cnt++;
					visited[i][j] = true;
					while (!q.empty()) {
						int now_x = q.front().first;
						int	now_y = q.front().second;
						q.pop();
						
						//범위 내 상하좌우 ? 
						if (now_x - 1 >= 1) {
							if (box[now_x - 1][now_y] > *iter) {
								if (!visited[now_x - 1][now_y]) {
									q.push({ now_x - 1, now_y });
									visited[now_x - 1][now_y] = true;
								}
							}
						}
						if (now_x + 1 <= n) {
							if (box[now_x + 1][now_y] > *iter) {
								if (!visited[now_x + 1][now_y]) {
									q.push({ now_x + 1, now_y });
									visited[now_x + 1][now_y] = true;
								}
							}
						}
						if (now_y - 1 >= 1) {
							if (box[now_x][now_y - 1] > *iter) {
								if (!visited[now_x][now_y - 1]) {
									q.push({ now_x, now_y - 1 });
									visited[now_x][now_y - 1] = true;
								}
							}
						}
						if (now_y + 1 <= n) {
							if (box[now_x][now_y + 1] > *iter) {
								if (!visited[now_x][now_y + 1]) {
									q.push({ now_x, now_y + 1 });
									visited[now_x][now_y + 1] = true;
								}
							}
						}
					}
				}
			}
			if (maximum <= cnt) {
				maximum = cnt;
			}
		memset(visited, 0, sizeof(visited));
	}
	cout << maximum;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> box[i][j];
			s.insert(box[i][j]);
		}
	}
	s.insert(0);
	findArea();
}