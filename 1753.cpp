#include <iostream>
#include <utility>
#include <queue>

#define INF 99999;
using namespace std;

int dis[20001];
int min_dis=INF;

vector<pair<int, int>> route[20001];
priority_queue<pair<int,int>> pq;
void daijkstra() {
	int from = pq.top().second;
	int distance = pq.top().first;
	
	if (pq.size()!=0) {
		pq.pop();
		for (int i = 0; i < route[from].size(); i++) {
			if (distance - route[from][i].first > dis[route[from][i].second]) {
				dis[route[from][i].second] = distance - route[from][i].first;
				pq.push(make_pair(dis[route[from][i].second], route[from][i].second));
				if (i == route[from].size() - 1) {
					daijkstra();
				}
			}
		}
	}
}

int main() {
	int v, e, start;
	int from, to, road;
	for (int i = 1; i < 9; i++) {
		dis[i] = -INF;
	}
	cin >> v >> e >> start;
	dis[start] = 0;
	for (int i = 0; i < e; i++) {
		cin >> from >> to >> road;
		route[from].push_back(make_pair(road, to));
	}
	pq.push(make_pair(0, start));
	daijkstra();

	for (int i = 1; i <= v; i++) {
		if (dis[i] == -99999) {
			cout << "INF" << "\n";
		}
		else {
			cout << -dis[i] << "\n";
		}
	}
}