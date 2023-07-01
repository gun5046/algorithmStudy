#include <iostream>
#include <queue>

using namespace std;

int map[16][16];
int start_x,start_y, end_x, end_y;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1, 0, 0,-1 };
bool visited[16][16];
bool flag = false;
void dfs(int x, int y) {
	if (x == end_x && y == end_y) {
		flag = true;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 16 || ny >= 16 || nx <= 0 || ny <= 0) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] == 1) continue;
		visited[nx][ny] = true;
		dfs(nx, ny);
		visited[nx][ny] = false;
	}
	
}
int main() {

	int t;
	
	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> t;
		flag = false;
		for (int i = 0; i < 16; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < 16; j++) {
				visited[i][j] = false;
				map[i][j] = str[j]-'0';
				if (map[i][j] == 2) {
					start_x = i;
					start_y = j;
				}
				else if (map[i][j] == 3) {
					end_x = i;
					end_y = j;
				}
			}
		}
		visited[start_x][start_y] = true;
		dfs(start_x, start_y);
		cout << flag << "\n";


	}
}