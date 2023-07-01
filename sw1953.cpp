#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int test;
int n, m;
int r, c,l;
int arr[50][50];
vector<vector<pair<int, int>>>d;
bool visited[50][50];

void init() {
	vector<pair<int, int>>temp;

	temp.push_back({ 1,0 });
	temp.push_back({ 0,1 });
	temp.push_back({ -1,0 });
	temp.push_back({ 0,-1 });
	d.push_back(temp);

	temp.clear();
	temp.push_back({ 1,0 });
	temp.push_back({ -1, 0 });
	d.push_back(temp);

	temp.clear();
	temp.push_back({ 0,1 });
	temp.push_back({ 0, -1 });
	d.push_back(temp);

	temp.clear();
	temp.push_back({ 0,1 });
	temp.push_back({ -1, 0 });
	d.push_back(temp);

	temp.clear();
	temp.push_back({ 1,0 });
	temp.push_back({ 0, 1 });
	d.push_back(temp);

	temp.clear();
	temp.push_back({ 0,-1 });
	temp.push_back({ 1, 0 });
	d.push_back(temp);

	temp.clear();
	temp.push_back({ 0,-1 });
	temp.push_back({ -1, 0 });
	d.push_back(temp);

	memset(visited, 0, sizeof(visited));
}

int main() {
	cin >> test;
	for (int t = 1; t <= test; t++) {
		
		cin >> n >> m;
		cin >> r >> c;
		cin >> l;
	
		init();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		
		queue<pair<int, pair<int,int>>>q;
		q.push({ 1, { r, c } });
		visited[r][c] = true;
		int cnt = 0;

		while (!q.empty()) {
			int time = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;

			q.pop();
			int now_v = arr[x][y];
			cnt++;

			for (int i = 0; i < d[now_v - 1].size(); i++) {
				pair<int, int>dir = { d[now_v - 1][i].first , d[now_v - 1][i].second };
				int nx = x+dir.first;
				int ny = y + dir.second;
				
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (arr[nx][ny] == 0) continue;
				if (visited[nx][ny]) continue;
				if (time + 1 > l) continue;
				bool flag = false;
				for (int j = 0; j < d[arr[nx][ny] - 1].size(); j++) {
					if (d[arr[nx][ny]-1][j].first == -dir.first && d[arr[nx][ny]-1][j].second == -dir.second) {
						flag = true;
						break;
					}
				}
				if (!flag) continue;
				visited[nx][ny] = true;
				q.push({ time + 1,{nx,ny} });
			}
		}

		cout << "#" << t << " " << cnt << "\n";

	}
}