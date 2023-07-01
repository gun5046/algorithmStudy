#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int res=0;
int arr[17][17];

int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };
class Pipe {
public :
	int cur_x = 0;
	int cur_y = 1;

	int dir = 0; // 가로 0 대각 1 세로 2
};

void move(Pipe p) {
	if (p.cur_x == n - 1 && p.cur_y == n - 1) {
		res++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = p.cur_x + dx[i];
		int ny = p.cur_y + dy[i];
		
		if ((p.dir == 0 && i == 1) || p.dir == 1 && i == 0) continue;
		if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1) {
			continue;
		}
		if (arr[nx][ny] == 1) {
			continue;
		}
				
		if (i == 2 && (arr[nx][ny - 1] == 1 || arr[nx - 1][ny] == 1)) continue;

		Pipe np;
		np.dir = i;
		np.cur_x = nx;
		np.cur_y = ny;

		move(np);

	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	Pipe p;
	move(p);

	cout << res;
}