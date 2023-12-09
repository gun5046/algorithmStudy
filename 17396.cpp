#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>
#include <time.h>
#define INF 999999999
using namespace std;


int n, m;
int arr[100000];
vector<pair<int,int>>v[100000];
priority_queue<pair<int, int>>pq;

int visited[100000];
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		v[a].push_back({ b,t });
		v[b].push_back({ a,t });
	}
	
	for (int i = 0; i < n; i++) {
		visited[i] = INF;
	}

	int start = 0;
	pq.push({ 0,0 });
	
	while (!pq.empty()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nval = v[now][i].second;
			if (arr[next] == 1 && next != n-1) continue;
			if (val + nval >= visited[next]) continue;
			visited[next] = val + nval;
			pq.push({val+nval, next});
		}
	}
	if (visited[n - 1] != INF) {
		cout << visited[n - 1];
	}
	else {
		cout << -1;
	}
}