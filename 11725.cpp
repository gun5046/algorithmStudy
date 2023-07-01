#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int>v[100001];
int arr[100001];
bool visited[100001];
int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	queue<int>q;

	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (visited[next]) continue;
			arr[next] = node;
			visited[next] = true;
			q.push(next);
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << arr[i] << "\n";
	}
}