#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;


int n, m, k;
bool power[1001];
vector<pair<int, int>>v[1001];
priority_queue<pair<int,pair<int, int>>>pq;
int parent[1001];

int findParent(int p) {
	if (parent[p] == p) {
		return p;
	}
	return parent[p] = findParent(parent[p]);
}

bool compareParent(int a, int b) {
	int ap = findParent(a);
	int bp = findParent(b);

	if (ap == bp)
		return true;
	return false;
}

void unionParent(int a, int b) {
	int ap = findParent(a);
	int bp = findParent(b);

	parent[bp] = ap;
}

int total = 0;
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int n1;
		cin >> n1;
		power[n1] = true;
	}
	for (int i = 0; i < m; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		pq.push({ -n3,{n1,n2} });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	//cout << "¿©±â";
	while (!pq.empty()) {
		int val = -pq.top().first;
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;

		pq.pop();
		//cout << n1 << " " << n2 << "\n";
		/*if (n1 == 8 && n2 == 9) {
			cout << "ASd";
		}*/
		//cout << "parent" << parent[n1] << " " << parent[n2] << "\n";
		if (parent[n1] == parent[n2]) continue;
		if (power[parent[n1]] && power[parent[n2]]) continue;
		else if (power[parent[n1]] && !power[parent[n2]]) {
			unionParent(n1, n2);
		}
		else if (!power[parent[n1]] && power[parent[n2]]) {
			unionParent(n2, n1);
		}
		else {
			if (n1 < n2) {
				unionParent(n1, n2);
			}
			else {
				unionParent(n2, n1);
			}
		}
		findParent(n1);
		findParent(n2);
		total += val;
	}

	cout << total;
}