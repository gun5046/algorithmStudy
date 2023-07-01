#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int arr[100][100][100];
vector<pair<int, pair<int, int>>>v;
int dx[6] = { 0, 1, -1, 0,0, 0};
int dy[6] = { 1, 0, 0,-1, 0, 0};
int dz[6] = { 0,0,0,0,1, -1};
bool visit[100][100][100];
int main() {
	int m, n, h;

	cin >> m >> n >> h;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					v.push_back({ i,{ j,k } });
				}
			}
		}
	}
	
	queue<pair<pair<int,int>, pair<int, int>>>q;

	for (pair<int, pair<int, int>> p : v) {
		int i = p.first;
		int j = p.second.first;
		int k = p.second.second;

		q.push({ {0, i}, {j,k} });
		visit[i][j][k] = true;
	}
	int t=0;
	while (!q.empty()) {
		 t= q.front().first.first;
		 int z = q.front().first.second;
		 int x = q.front().second.first;
		 int y = q.front().second.second;
		 q.pop();
		 for (int i = 0; i < 6; i++) {
			 int nx = x + dx[i];
			 int ny = y + dy[i];
			 int nz = z + dz[i];

			 if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			 if (visit[nz][nx][ny]) continue;
			 if (arr[nz][nx][ny] == 1 || arr[nz][nx][ny] == -1) continue;
			 visit[nz][nx][ny] = true;
			 arr[nz][nx][ny] = 1;
			 q.push({ { t + 1, nz }, { nx,ny }});
		 }
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}

	cout << t;
	return 0;
}