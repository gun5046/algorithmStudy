#include <iostream>
#include <vector>

using namespace std;

int n, m, p1, p2, x, y, cnt;
vector<int>v[101];
bool visited[101] = { false, };

void family(int start, int c) {
	if (start == p2) {
		cnt = c;
	}
	else {
		int size = v[start].size();
		for (int i = 0; i < size; i++) {
			int next = v[start][i];
			if (!visited[next]) {
				visited[next] = true;
				family(next,c+1);
			}
		}
	}
}

int main() {
	cin >> n >> p1 >> p2 >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[y].push_back(x);
		v[x].push_back(y);
	}
	
	family(p1, 0);
	if (cnt == 0) {
		cout << -1;
	}
	else {
		cout << cnt;
	}
}