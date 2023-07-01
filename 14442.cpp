#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
#include <algorithm>
#include <string>
#include <cstring>
#define INF 99999999
using namespace std;

int n, m, k;
int arr[1000][1000];
int break_wall[1000][1000];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int findWay() {
	queue<pair<pair<int,int>,pair<int,int>>>q;
	q.push({ {0,0} ,{0,1}});
	break_wall[0][0] = 0;

	while (!q.empty()) {
		int wall = q.front().second.first;
		int moving = q.front().second.second;
		int x = q.front().first.first;
		int y = q.front().first.second;
		q.pop();
		if (x == n - 1 && y == m - 1) return moving;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (break_wall[nx][ny] <= wall) continue;
			if (arr[nx][ny] == 1) {
				if (wall < k && break_wall[nx][ny] > wall+1) {
					break_wall[nx][ny] = wall + 1;
					q.push({ {nx,ny} ,{wall + 1,moving+1} });
				}
			}
			else {
				break_wall[nx][ny] = wall;
				q.push({ {nx,ny},{wall, moving+1} });
			}
		}
	}
	return -1;
}
int main() {
	cin >> n>>m >>k;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j]-'0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			break_wall[i][j] = INF;
		}
	}
	
	cout << findWay();
}