#include <iostream>
#include <utility>
#include <queue>

#define INF 99999999
using namespace std;

int dis[20001];
int min_dis=INF;

vector<pair<int, int>> route[20001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
void daijkstra() {
	
	while (!pq.empty()) {
		int from = pq.top().second;
		int dist = pq.top().first;

		pq.pop();
		for (int i = 0; i < route[from].size(); i++) {
			int to = route[from][i].second;
			int ndist = route[from][i].first;
			if (dist + ndist < dis[to]) {
				
				dis[to] = dist + ndist;
				pq.push({dis[to], to});
				
			}
		}
	}
}


int main() {
	int v, e, start;
	int from, to, road;
	
	cin >> v >> e >> start;
	for (int i = 1; i <= v; i++) {
		dis[i] = INF;
	}
	dis[start] = 0;
	for (int i = 0; i < e; i++) {
		cin >> from >> to >> road;
		route[from].push_back(make_pair(road, to));
	}
	pq.push(make_pair(0, start));
	daijkstra();

	for (int i = 1; i <= v; i++) {
		if (dis[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << dis[i] << "\n";
		}
	}
}