#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 99999999
using namespace std;

int n, m;
vector<pair<int,int>>v[50001];
int arr[50001];
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back(make_pair( b,c ));
		v[b].push_back({ a,c });
	}

	for (int i = 0; i <= n; i++) {
		arr[i] = INF;
	}
	priority_queue<pair<int,int>>pq;
	arr[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		pair<int,int> now = pq.top();
		int pos = now.second;
		int val = -now.first;
		pq.pop();

		for (int i = 0; i < v[pos].size(); i++) {
			pair<int, int> next = v[pos][i];
			
			if (arr[next.first] <= val + next.second) continue;

			arr[next.first] = val + next.second;
			pq.push({-(val+next.second), next.first});
			
		}
	}

	cout << arr[n];
	return 0;
}