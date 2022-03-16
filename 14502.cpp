#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int map[9][9];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[9][9] = { false, };

pair<int, int> wall[3];
void virus() {
	
	
}


int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {	
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	int t1=1, t2=1;
	
	int wallCnt = 0;
			for (int i = t1; i <= n; i++) {
				for (int j = t2; j <= m; j++) {
					if (wallCnt == 3) {
						t2 = j;
						break;
					}
					if (map[i][j] == 0) {
						map[i][j] = 1;
						wall[wallCnt] = {i,j};
						wallCnt++;
					}
				}
				if (wallCnt == 3) {
					t1 = i;
					break;
				}
			}
			virus();
	
}
