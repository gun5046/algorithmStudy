#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
int population[10];
vector<int>v[11];
int total = 0;
int avg=0;
int min_res = 99999;
void start(int x) {
	bool visited[11];
	memset(visited, 0, sizeof(visited));
	queue<pair<int,int>>q;

	q.push({ x , population[x]});
	visited[x] = true;

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_t = q.front().second;
		q.pop();

		for (int i = 0; i < v[now_x].size(); i++) {
			int nx = v[now_x][i];
			int t = population[nx];
			
			if (visited[nx]) continue;
			
			visited[nx] = true;
			q.push({ nx, now_t + t });
			if (avg - now_t - t < min_res) {
				min_res = total - now_t - t;
			}
		}
	}
	
}
void ward() {
	for (int i = 1; i <= n; i++) {
		start(i);
	}
}
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> population[i];
		total += population[i];
	}
	avg = total / n;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;

		for (int j = 0; j < m; j++) {
			int nm;
			cin >> nm;
			v[i].push_back(nm);
		}
	}

	ward();
	if (min_res == 99999) {
		cout << -1;
	}
	else {
		cout << min_res;
	}
}