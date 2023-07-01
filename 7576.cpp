#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int arr[1000][1000];
vector<pair<int, int>>v;
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0,-1 };
bool visit[1000][1000];
int main() {
	int m, n;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				v.push_back({ i,j });
			}
		}
	}

	queue<pair<int, pair<int, int>>>q;

	for (pair<int, int> p : v) {
		int i = p.first;
		int j = p.second;

		q.push({ 0, {i,j} });
		visit[i][j] = true;
	}
	int t = 0;
	while (!q.empty()) {
		t = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] == 1 || arr[nx][ny] == -1) continue;
			visit[nx][ny] = true;
			arr[nx][ny] = 1;
			q.push({ t + 1, { nx,ny } });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << t;
	return 0;
}