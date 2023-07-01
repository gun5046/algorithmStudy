#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int n, m;
vector<int>v[32001];
queue<int>q;
int arr[32001];
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		arr[n2]++;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			q.push(i);
			cout << i << " ";
		}
	}

	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (int i = 0; i < v[s].size(); i++) {
			int ns = v[s][i];
			if (--arr[ns] == 0) {
				cout << ns << " ";
				q.push(ns);
			}
		}
	}
}