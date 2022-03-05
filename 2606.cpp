#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<int>v[101];
queue<int> q;
bool visited[101] = { false, };

int virus(int a) {
	q.push(a);
	visited[a] = true;
	int cnt=-1;
	while (!q.empty()) {
		cnt++;
		int num = q.front();
		q.pop();
		int size = v[num].size();
		for (int i = 0; i < size; i++) {
			int next = v[num][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return cnt;
}

int main() {
	int num1, num2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	
	cout << virus(1);
}