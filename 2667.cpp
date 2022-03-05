#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int n, sum=0;
int box[26][26];
int visited[26][26] = { false, };
string str;
priority_queue<int>compNum;
queue<pair<int,int>>q;
bool confirmHouse(int x, int y) {
	if (box[x][y] == 1) {
		if (!visited[x][y]) {
			visited[x][y] = true;
			return true;
		}
	}
	return false;
}

void housingComplex(int x, int y) {
	int cnt = 0;
	visited[x][y] = true;
	q.push({ x, y });
	while (!q.empty()) {
		cnt++;
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		if (now_x - 1 >= 1) {
			if (confirmHouse(now_x - 1, now_y)) {
				q.push({now_x-1,now_y});
			}
		}
		if (now_x + 1 <= n) {
			if (confirmHouse(now_x + 1, now_y)) {
				q.push({ now_x + 1,now_y });
			}
		}
		if (now_y - 1 >= 1) {
			if (confirmHouse(now_x, now_y-1)) {
				q.push({ now_x, now_y-1 });
			}

		}
		if (now_y + 1 <= n) {
			if (confirmHouse(now_x, now_y+1)) {
				q.push({ now_x, now_y+1 });
			}
		}	
	}
	compNum.push(-cnt);
}

void findHouse() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (box[i][j] == 0) {
				continue;
			}
			if (visited[i][j]) {
				continue;
			}
			housingComplex(i,j);
			sum++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= n; j++) {
			box[i][j] = str[j - 1]-'0';
		}
	}

	findHouse();

	cout << sum<<endl;

	while (!compNum.empty()) {
		cout << -compNum.top() << "\n";
		compNum.pop();
	}
}