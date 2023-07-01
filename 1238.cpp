#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 99999999
using namespace std;

int n, m, x;
vector<pair<int,int>>v[1001];
int home[1001];
int arr[1001];
priority_queue<int>res;
void findRoad(int start) {
	priority_queue<pair<int,int>>pq;
	arr[start] = 0;

	pq.push({ 0, start });
	while (!pq.empty()) {
		int idx = pq.top().second;
		int t = -pq.top().first;
			
		pq.pop();
		if (x == idx) {
			break;
		}
		for (int i = 0; i < v[idx].size(); i++) {
			int nidx = v[idx][i].first;
			int nt = v[idx][i].second;

			if (arr[nidx] <= t + nt) continue;
			arr[nidx] = t + nt;
			pq.push({ -arr[nidx], nidx });
		}
	}
	
	res.push(arr[x]+home[start]);
	return;
}

void backHome() {
	priority_queue<pair<int, int>>pq;
	home[x] = 0;

	pq.push({ 0, x });
	while (!pq.empty()) {
		int idx = pq.top().second;
		int t = -pq.top().first;

		pq.pop();
		
		for (int i = 0; i < v[idx].size(); i++) {
			int nidx = v[idx][i].first;
			int nt = v[idx][i].second;

			if (home[nidx] <= t + nt) continue;
			home[nidx] = t + nt;
			pq.push({ -home[nidx], nidx });
		}
	}
}

void sol() {
	for (int i = 1; i <= n; i++) {
		home[i] = INF;
	}
	backHome();
	
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;

		for (int j = 1; j <= n; j++) {
			arr[j] = INF;
		}

		findRoad(i);
	}
}

int main() {
	cin >> n >> m >> x;

	for (int i = 1; i <= m; i++) {
		int n1, n2, t1;
		cin >> n1 >> n2 >> t1;

		v[n1].push_back({ n2,t1 });
	}

	sol();

	cout << res.top();
}