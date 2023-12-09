#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 99999999
using namespace std;
vector<pair<int, int>>v[501];
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	long long arr[501];
	for (int i = 1; i <= n; i++) {
		arr[i] = INF;
	}

	arr[1] = 0;
	bool check = false;	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=n; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int next = v[j][k].first;
				int cost = v[j][k].second;
				if (arr[j] != INF &&arr[next] > cost + arr[j]) {
					arr[next] = cost + arr[j];
					if (i == n) {
						check = true;
					}
				}
			}
		}
	}
	if (check) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (arr[i] == INF)
				cout << -1 << "\n";
			else
				cout << arr[i] << "\n";
		}
	}
}