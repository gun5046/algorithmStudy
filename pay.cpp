#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <set>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

vector<vector<int>>answer;

bool flag = false;
int rec[11];
int bottom;
int map[21][21];
bool checked[21][21];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

bool check(int x, int len, int n, int m) {
	queue<pair<int, int>>q;
	q.push({ x,bottom });
	bool checkinstance[21][21];
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			checkinstance[i][j] = 0;
		}
	}

	checkinstance[x][bottom] = 1;
	bool recflag = false;

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;

		q.pop();

		if (nx - x >= len || ny - bottom >= len) continue;

		for (int i = 0; i < 2; i++) {
			int next_x = nx + dx[i];
			int next_y = ny + dy[i];

			if (next_x > n || next_y > m) {
				recflag = true;
				break;
			}
			if (checkinstance[next_x][next_y])continue;
			if (checked[next_x][next_y]) {
				recflag = true;
				break;
			}
			q.push({ next_x, next_y });
			checkinstance[next_x][next_y] = 1;
		}
		if (recflag) break;
	}

	if (recflag) {
		return 0;
	}
	else {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				checked[x + i][bottom + j] = true;
			}
		}
		return 1;
	}
}

void put(int len, int cnt, int n, int m) {
	for (int i = 0; i < n; i++) {
		if (cnt==0) return;
		if (bottom + len > m) return;
		if (checked[i][bottom])continue;
		if (i + len > n) {
			++bottom;
			i = -1;
			continue;

		}
		cout << i << " " << bottom << " " << "\n";
		if (check(i, len, n, m)) {
			i += len - 1;
			vector<int>temp;
			temp.push_back(i);
			temp.push_back(bottom);
			answer.push_back(temp);
			cnt--;
		}
	}
}

vector<vector<int>> solution(int n, int m, vector<vector<int>> rectangle) {
	for (vector<int> v : rectangle){
		int len = v[0];
		int num = v[1];
		rec[len] = num;
	}
	int len = 0;

	while (len <= 10) {
		len++;
		if (rec[len]==0)continue;
		put(len, rec[len], n, m);
	}
	return answer;
}

int main() {
	vector<vector<int>>s;
	vector<int>v;
	v.push_back(2);
	v.push_back(2);
	s.push_back(v);

	v.clear();
	v.push_back(1);
	v.push_back(4);
	s.push_back(v);
	v.clear();
	v.push_back(3);
	v.push_back(2);
	s.push_back(v);
	solution(7, 8, s );
}