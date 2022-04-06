#include <iostream>
#include <vector>
#include <cstring>
#define stop 4

using namespace std;

int dx[4] = { 0, 1,0,-1 };
int dy[4] = { -1, 0,1,0 };
int n, m;
int r, c;
int d; //ºÏ 0 µ¿ 1 ³² 2 ¼­ 3
int box[50][50];
bool visited[50][50];
class Dir{
public :
	int d;
	Dir(int n) {
		this->d = n;
	}
	void turn() {
		switch (this->d) {
		case 0:
			this->d = 3;
			break;
		case 1:
			this->d = 0;
			break;

		case 2:
			this->d = 1;
			break;
		case 3:
			this->d = 2;
			break;
		}
	}

	int back() {
		switch (this->d) {
		case 0:
			return 2;
			break;
		case 1:
			return 3;
			break;
		case 2:
			return 0;
			break;
		case 3:
			return 1;
			break;
		}
	}
};

void robotClean(int r, int c, int d);
int main() {

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
		}
	}
	memset(visited, true, sizeof(visited));
	robotClean(r,c, d);
}

void robotClean(int r, int c, int d) {
	Dir dir(d);
	int cnt = 0;
	int now_x=r, now_y=c;
	int clean=1;
	visited[now_x][now_y] = 0;
	while (1) {
		
		if (cnt == stop) {
			if(box[now_x + dy[dir.back()]][now_y + dx[dir.back()]] == 1)
				break;
			else {
				now_x += dy[dir.back()];
				now_y += dx[dir.back()];
				cnt = 0;
				continue;
			}
		}
		dir.turn();
		
		int next_x = now_x + dy[dir.d];
		int next_y = now_y + dx[dir.d];
		if (next_x <0 || next_y <0 || next_x>n - 1 || next_y>m - 1) {
			cnt++;
			continue;
		}
		if (!visited[next_x][next_y]) {
			cnt++;
			continue;
		}
		if (box[next_x][next_y] == 1) {
			cnt++;
			continue;
		}

		now_x = next_x; now_y = next_y;
		cnt = 0;
		clean++;
		visited[now_x][now_y] = false;
		box[now_x][now_y] = 2;
		
	}

	cout << clean;

	return;
}