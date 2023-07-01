#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;

int n, m;
int arr[1000][1000];
int father[1000][1000];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int c = 0;
bool visit[1000][1000];
vector<int>v;
int answer[1000][1000];
void findRoad(int fx, int fy) {
	queue<pair<int,int>>q;
	
	visit[fx][fy] = true;
	father[fx][fy] = c;
	q.push({ fx,fy });
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		cnt++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny <0 || nx>=n || ny >= m) continue;
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] == 1) continue;
			visit[nx][ny] = true;
			father[nx][ny] = c;
			q.push({ nx,ny });
		}
	}
	v.push_back(cnt);
	c++;
}

void sol() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(arr[i][j] == 0 && !visit[i][j])
				findRoad(i,j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				set<int> s;
				int temp=1;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (arr[nx][ny] == 1) continue;
					s.insert(father[nx][ny]);
				}
				for (int num : s) {
					temp += v[num];
				}
				answer[i][j] = temp;
			}
			else {
				answer[i][j] = 0;
			}
		}
	}

}
int main() {
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j]-'0';
		}
	}

	sol();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j]%10;
		}
		cout << "\n";
	}
}

