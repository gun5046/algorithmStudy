#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <string>
#include <list>
#include <sstream>

using namespace std;

int test,n;
int arr[13][13];

vector<pair<int,int>>pc;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int max_line=9999, max_connect=0;
void dfs(int idx, int line, int connect) {
	if (idx == pc.size()) {
		//cout << "connect : " << connect << " line : " << line<<"\n";
		if (connect > max_connect) {
			max_connect = connect;
			max_line = line;
		}
		else if (connect == max_connect) {
			if (max_line > line) {
				max_line = line;
			}
		}
		return;
	}

	
		int x = pc[idx].first;
		int y = pc[idx].second;

		for (int j = 0; j < 4; j++) {
			vector<pair<int, int>>v;
			int nx = x;
			int ny = y;
			//cout <<"start "<< idx << " : " <<"\n";
			bool flag = false;
			while (1) {
				nx = nx + dx[j];
				ny = ny + dy[j];
				//cout << nx << " " << ny << "\n";
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
					flag = true;
					break;
				}
				if (arr[nx][ny] != 0) {
					break;
				}
				v.push_back({ nx, ny });
			}
			/*if (flag) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}*/
			if (flag) {
				for (int k = 0; k < v.size(); k++) {
					arr[v[k].first][v[k].second] = 2;
				}
				dfs(idx + 1, line+v.size(), connect+1);
				for (int k = 0; k < v.size(); k++) {
					arr[v[k].first][v[k].second] = 0;
				}
			}
			else {
				if (max_connect <= pc.size() - idx - 1 + connect) {
					dfs(idx + 1, line, connect);
				}
			}
		}
	
}

void sol() {
	dfs(0, 0, 0);
}

int main() {
	cin >> test;

	for (int t = 1; t <= test; t++) {
		cin >> n;
		while (!pc.empty()) {
			pc.pop_back();
		}
		max_line = 9999; max_connect = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1 && i!=0 && i != n-1 && j!=0 && j!=n-1) {
					pc.push_back({ i,j });
				}
			}
		}

		sol();
		cout << "#" << t <<" "<< max_line << "\n";
	}
}