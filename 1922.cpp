#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>>v[1001];
int parent[1001];

int findParent(int s) {
	if (parent[s] == s) {
		return s;
	}
	return parent[s] = findParent(parent[s]);
}

void unionfind(int a, int b) {
	int ap = findParent(a);
	int bp = findParent(b);
	if (ap < bp) {
		parent[bp] = ap;
	}
	else {
		parent[ap] = bp;
	}
}

bool compareParent(int a,int b) {
	int ap = findParent(a);
	int bp = findParent(b);

	if (ap == bp) {
		return true;
	}
	else {
		return false;
	}
}
priority_queue<pair<int,pair<int, int>>>pq;
int total=0;
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		pq.push({ -n3,{n1,n2} });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	while (!pq.empty()) {
		int val = pq.top().first;
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		pq.pop();
		if (compareParent(n1, n2)) {
			continue;
		}
		unionfind(n1, n2);
		total += val;
	}
	cout << -total;
}