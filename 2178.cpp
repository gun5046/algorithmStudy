#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int n, m;
int box[101][101];
string row;
bool visited[101][101] = { false , };
bool findNM = false;
class node {
public:
	int x=1;
	int y=1;
	int c=1;

	node(int x, int y, int c) {
		this->x = x;
		this->y = y;
		this->c = c;
	}
};

queue<node>q;

bool confirm(int x, int y) {
	if (box[x][y] == 1) {
		if (!visited[x][y]) {
			visited[x][y] = true;
			return 1;
		}
	}
	return 0;
}

int maze(node nd) {
	//상하좌우가 범위내? , 방문한곳? , 0이냐 1이냐? , n,m이냐?
	q.push(nd);
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int c = q.front().c;
		q.pop();
		if (x == n && y == m) {
			return c;
		}
		else {
			if (x - 1 >= 1) {
				if (confirm(x-1,y)) {
					q.push(node(x - 1, y, c+1));
				}
			}
			if (x + 1 <= n) {
				if (confirm(x + 1, y)) {
					q.push(node(x + 1, y, c+1));
				}
			}
			if (y - 1 >= 1) {
				if (confirm(x, y-1)) {
					q.push(node(x, y-1, c+1));
				}
			}
			if (y + 1 <= m) {
				if (confirm(x, y+1)) {
					q.push(node(x, y+1, c+1));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> row;
		for (int j = 1; j <= m; j++) {
			box[i][j]=row[j - 1]-'0';
		}
	}
	node start = node(1, 1, 1);
	visited[1][1] = true;
	cout << maze(start);
}