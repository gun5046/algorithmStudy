#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;


int v, e;
bool visit[10001];
priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>>pq;
vector<pair<int, int>>v1[10001];

int main() { //Prim
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		v1[n1].push_back({n3, n2});
		v1[n2].push_back({ n3,n1 });
	}

	
	long long sum=0;
	
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int x = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		
		if (visit[x]) continue;
		visit[x] = 1;
		sum += d;
		for (int i = 0; i < v1[x].size(); i++) {
			int nx = v1[x][i].second;
			int nd = v1[x][i].first;

			pq.push({nd,nx});
		}
	}
	cout << sum;
}



/*
int v, e;

priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

int set[10001];  //Kruskal

int getParent(int x) {
	if (set[x] == x) {
		return x;
	}
	return set[x] = getParent(set[x]);
}

bool find(int x, int y) {
	int xp = getParent(x);
	int yp = getParent(y);

	if (xp != yp) {
		return false;
	}
	return true;
}

void unionParent(int x, int y) {
	int xp = getParent(x);
	int yp = getParent(y);

	if (xp < yp) {
		set[yp] = set[xp];
	}
	else {
		set[xp] = set[yp];
	}
}

int main() {
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		pq.push({ n3, {n1,n2} });
	}

	for (int i = 1; i <= v; i++) {
		set[i] = i;
	}
	long long sum = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		pq.pop();
		if (!find(n1, n2)) {
			sum += d;
			unionParent(n1, n2);
		}
	}

	cout << sum;
}*/