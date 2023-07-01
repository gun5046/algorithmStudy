#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int n1, n2, n3;
vector<pair<int, int>>v[10001];
int arr[10001];
int max1 = 0;
void solution(int node, int d, int pre_node) {
	if (v[node].size() == 0) {
		return;
	}

	for (int i = 0; i < v[node].size(); i++) {
		int n_node = v[node][i].first;
		int nd = d + v[node][i].second;
		if (n_node == pre_node) continue;
		if (max1 < nd) {
			max1 = nd;
		}


		solution(n_node, nd, node);

	}
}
//arr[n_node]=nd;
int main() {

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> n1 >> n2 >> n3;
		v[n1].push_back({ n2,n3 });
		v[n2].push_back({ n1,n3 });
	}
	priority_queue<int>pq;
	for (int i = 1; i <= n; i++) {
		solution(i, 0, 0);
	}

	cout << max1;
}