#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int r,c;
char arr[1500][1500];
vector<pair<int, int>>start;
bool visited[1500][1500];
int res = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>>water_q;

void waterMelt() {
	queue<pair<int,int>>q;
	q.push(start[0]);
	visited[start[0].first][start[0].second] = true;
	vector<pair<int, int>> v;
	
	while (1) {
		queue<pair<int, int>>next;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (start[1] == make_pair(nx, ny)) {
					return;
				}
				if (visited[nx][ny]) continue;
				
				else if (arr[nx][ny] == 'X') {
					next.push({ nx,ny });
				}
				else{
					q.push({ nx,ny });
				}
				visited[nx][ny] = true;
			}
		}

		q = next;
		res++;
		int water_c = water_q.size();
		while (water_c!=0) {
			int x = water_q.front().first;
			int y = water_q.front().second;
			water_q.pop();
			water_c--;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (arr[nx][ny] == 'X') {
					water_q.push({ nx,ny });
					arr[nx][ny] = '.';
				}
			}
		}
	}

}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'L') {
				start.push_back({ i,j });
				arr[i][j] == '.';
				water_q.push({ i,j });
			}
			else if (arr[i][j]=='.') {
				water_q.push({ i,j });
			}
		}
	}
	waterMelt();
	cout << res;
}