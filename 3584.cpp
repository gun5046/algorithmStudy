#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;

int t,n;
int parent[10001];
int depth[10001];
vector<int>v[10001];

void findDepth(int p,int d) {
	for (int i = 0; i < v[p].size(); i++) {
		depth[v[p][i]] = d + 1;
		findDepth(v[p][i],d + 1);
	}
}

void findCommonAncestor(int n1, int n2) {
	if (n1 == n2) {
		cout << n1 << "\n";
		return;
	}
	if (depth[n1] == depth[n2]) {
		
		int p1 = parent[n1];
		int p2 = parent[n2];
		while (p1!=p2) {
			p1 = parent[p1];
			p2 = parent[p2];
		}
		cout << p1 << "\n";
		return;
	}
	else {
		if (depth[n1] < depth[n2]) {
			findCommonAncestor(n1, parent[n2]);
		}
		else {
			findCommonAncestor(parent[n1], n2);
		}
	}

}

int main() {
	cin >> t;

	for (int test = 0; test < t; test++) {
		memset(parent, 0, sizeof(parent));
		memset(depth, 0, sizeof(parent));
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
		cin >> n;
		for (int i = 0; i < n-1; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			parent[n2] = n1;
			v[n1].push_back(n2);
		}
		int top;
		for (int i = 1; i <= n; i++) {
			if (parent[i] == 0) {
				top = i;
			}
		}

		depth[top] = 0;
		findDepth(top,0);

		int n1, n2;
		cin >> n1 >> n2;

		findCommonAncestor(n1, n2);
	}
}