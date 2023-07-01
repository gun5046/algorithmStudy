#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <sstream>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#define INF 99999999
using namespace std;

int n, m;
vector<pair<int, int>> v[1001];
bool check[1001];
int dis[1001];

void dijkstra(int start, int end) {
	dis[start] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({0,start});

	while (!pq.empty()) {
		int cs = -pq.top().first;
		int dst = pq.top().second;
		pq.pop();
		if (dis[dst] < cs) continue;
		for (int i = 0; i < v[dst].size(); i++) {
			int next = v[dst][i].first;
			int ncs = v[dst][i].second;

			if (dis[next] > cs + ncs) {
				dis[next] = cs + ncs;
				pq.push({ -dis[next], next});
			}
		}
	}
	
	cout << dis[end];
}
int main() {
	cin >> n >> m;
	int start, end, cost;
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;
		v[start].push_back({ end, cost });
	}
	cin >> start >> end;

	dijkstra(start, end);
}