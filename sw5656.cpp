#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n, w, h;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int, int>> q;
priority_queue<int>pq;

void destroy(int r,int c, vector<vector<int>>&arr) {
	int val = arr[r][c];
	arr[r][c] = 0;
	for (int i = 1; i <= val - 1; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = r + dx[j] * i;
			int ny = c + dy[j] * i;

			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (arr[nx][ny] == 0) continue;
			q.push({ nx,ny });
		}
	}
}

void drop(int depth, vector<vector<int>> v) {
	
	if (depth >= n) {
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (v[i][j] != 0) {
					cnt++;
				}
			}
		}
		pq.push(-cnt);
		return;
	}
	

	for (int i = 0; i < w; i++) {
		vector<vector<int>>v1 = v;
		for (int j = 0; j < h; j++) {
			if (v1[j][i] != 0) {
				q.push({ j, i });
				break;
			}
		}
		
		while (!q.empty()) {
			int x =	q.front().first;
			int y = q.front().second;
			q.pop();
			
			destroy(x, y, v1);
		}

		/*for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cout << v1[j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";*/

		for (int j = 0; j < w; j++) {
			for (int k = h - 1, l = h-1; k >= 0;) {
				if (v1[k][j] == 0) {
					k--;
					
				}
				else {
					int temp = v1[k][j];
					v1[k--][j] = 0;
					v1[l--][j] = temp;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (v1[i][j] != 0) {
					cnt++;
				}
			}
		}
		/*for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cout << v1[j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";*/
		drop(depth + 1, v1);
	}
}

void sol(vector< vector<int>>v) {
	drop(0,v);
}

int main() {
	int test;

	cin >> test;

	for (int t = 1; t <= test; t++) {
		cin >> n >> w >> h;
		while (!pq.empty()) {
			pq.pop();
		}
		vector<vector<int>>arr(15, vector <int>(12));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				
			}
		}

		sol(arr);
		cout << "#" << t << " " << -pq.top()<<"\n";
	}
}