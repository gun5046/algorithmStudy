#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, x, y, k, t;
int map[20][20];
vector<int> com;
int move1[5] = {0, 1, -1, 0, 0};
int move2[5] = {0, 0, 0, -1, 1};
int dice[6] = { 0, };
int temp[6];

void zeroBox(int r, int c) {
	map[r][c] = dice[5];
}

void nzeroBox(int r, int c) {
	dice[5] = map[r][c];
	map[r][c] = 0;
}

void dicing() {
	
	int r = x, c = y;
	int dir;
	for (int i = 0; i < com.size(); i++) {
		copy(dice, dice + 6, temp);
		dir = com[i];
		r += move2[dir]; c += move1[dir];
		if (r<0 || c<0 || r>n-1 || c > m-1) {
			r -= move2[dir]; c -= move1[dir];
			continue;
		}
		
		switch (dir) {
		case 1:
			dice[0] = temp[3];
			dice[2] = temp[0];
			dice[3] = temp[5];
			dice[5] = temp[2];
			break;
		case 2:
			dice[0] = temp[2];
			dice[2] = temp[5];
			dice[3] = temp[0];
			dice[5] = temp[3];
			break;
		case 3:
			dice[0] = temp[4];
			dice[1] = temp[0];
			dice[4] = temp[5];
			dice[5] = temp[1];
			break;
		case 4:
			dice[0] = temp[1];
			dice[1] = temp[5];
			dice[4] = temp[0];
			dice[5] = temp[4];
			break;
		}

		if (map[r][c] == 0) {
			zeroBox(r,c);
		}
		else {
			nzeroBox(r,c);
		}

		cout << dice[0] <<"\n";
	}
}


int main() {
	cin >> n >> m >> x >> y>> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> t;
		com.push_back(t);
	}

	dicing();
}