#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, v, num1, num2;
bool visitedDfs[1001] = { false, };
bool visitedBfs[1001] = { false, };
priority_queue <int> vt[1001];
priority_queue<int> vt1[1001];
queue <int> q;
void dfs(int v) { //¿Á±Õ or Ω∫≈√
	cout << v << " ";
	visitedDfs[v] = true;
	int size = vt[v].size();
	for (int i = 0; i < size; i++) {
		int next = -vt[v].top();
		vt[v].pop();
		if (!visitedDfs[next]) {
			dfs(next);
		}
	}
}
void bfs(int v) { //≈•
	q.push(-v);
	visitedBfs[v] = true;
	while (!q.empty()) {
		int now = -q.front();
		
		q.pop();
		cout << now << " ";
		int size = vt1[now].size();
		for (int i = 0; i < size; i++) {
			int next = vt1[now].top();
			vt1[now].pop();
			if (!visitedBfs[-next]) {
				q.push(next);
				visitedBfs[-next] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		vt[num1].push(-num2);
		vt[num2].push(-num1);
		vt1[num1].push(-num2);
		vt1[num2].push(-num1);
	}


	dfs(v);
	cout << endl;
	bfs(v);
}