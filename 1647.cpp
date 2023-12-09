#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>

using namespace std;

int n, m;
vector<pair<int, int>>v[100001];

priority_queue<pair<int, int>>pq;
bool visit[100001];
int total = 0;
int top = 0;
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		v[n1].push_back({ n2,n3 });
		v[n2].push_back({ n1,n3 });
	}

	pq.push({ 0,1 });
	while (!pq.empty()) {
		int now = pq.top().second;
		int val = pq.top().first;

		pq.pop();
		if (visit[now]) continue;
		visit[now] = true;
		total += val;
		top = max(top, -val);
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nv = v[now][i].second;

			pq.push({ -nv,next });
		}
	}

	cout << -total - top;

}