#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <sstream>
#include <math.h>
#include <list>
#include <deque>
#include <vector>

using namespace std;

struct Loc {
public :
	int x=0; int y=0;
	int block = 0;

	Loc(int x,int y, int b) {
		this->x = x;
		this->y = y;
		this->block = b;
	}
};

struct compare {
	bool operator()(const Loc& m1, const Loc& m2) {
		return m1.block > m2.block;
	}
};

int n, m;
int arr[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool visit[100][100];
priority_queue<Loc,vector<Loc>, compare>q;
int main() {
	cin >> n >> m;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		
		for (int j = 0; j < str.length(); j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	q.push(Loc(0,0,0));
	visit[0][0] = true;
	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int block = q.top().block;

		q.pop();

		if (x == m - 1 && y == n - 1) {
			cout << block;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nb = block;
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || visit[nx][ny]) continue;
			if (arr[nx][ny] == 1) nb += 1;
			visit[nx][ny] = true;
			q.push(Loc(nx,ny,nb));
		}
	}
}