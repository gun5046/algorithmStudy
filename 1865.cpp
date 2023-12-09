#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define INF 99999999
using namespace std;

int test;
int main() {
	cin >> test;
	for (int t = 0; t < test; t++) {
		int n, m, w;
		cin >> n >> m >> w;
		vector<pair<int, int>> road[501];
		int time[501];
		for (int i = 1; i <= n; i++) {
			time[i] = INF;
		}
		for (int i = 0; i < m; i++) {
			int n1, n2, n3;
			cin >> n1 >> n2 >> n3;
			road[n1].push_back({ n2,n3 });
			road[n2].push_back({ n1,n3 });

		}
		for (int i = 0; i < w; i++) {
			int n1, n2, n3;
			cin >> n1 >> n2 >> n3;
			road[n1].push_back({ n2,-n3 });
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < road[j].size(); k++) {
					int dst = road[j][k].first;
					int v = road[j][k].second;

					if (time[dst] <= time[j] + v) continue;
					time[dst] = time[j] + v;
				}
			}
		}
		bool check = false;
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < road[j].size(); k++) {
				int dst = road[j][k].first;
				int v = road[j][k].second;

				if (time[dst] > time[j] + v) {
					check = true;
					break;
				}
			}
		}
		if (check) {
			cout << "YES"<<"\n";
		}
		else {
			cout << "NO"<<"\n";
		}
		
	}
}