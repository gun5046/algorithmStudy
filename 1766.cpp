#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
vector<int>v[32001];
vector<int>start;
int arr[32001];
vector<int>dir;
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		arr[n2]++;
	}

	priority_queue<int>pq;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		int x = -pq.top();
		dir.push_back(x);
		pq.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];

			if (--arr[nx] == 0) {
				pq.push(-nx);
			}
		}
	}

	for (int i = 0; i < dir.size(); i++) {
		cout << dir[i] << " ";
	}
}