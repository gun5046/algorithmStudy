#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <limits>
using namespace std;
int arr[9][9];
bool row[9][10];
bool col[9][10];
bool box[3][3][10];
int res[9][9];

void init() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] != 0)
				col[i][arr[i][j]] = true;
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[j][i] != 0) {
				row[i][arr[j][i]] = true;
			}
		}
	}

	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j++) {
			for (int k = i*3; k < i*3 + 3; k++) {
				for (int l = j*3; l < j*3 + 3; l++) {
					if (arr[k][l] != 0)
						box[i][j][arr[k][l]] = true;
				}
			}
		}
	}
}

void sdoku(int x, int y) {

	if (x == 9) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
	if (arr[x][y] != 0) {
		if (y == 8)
			sdoku(x + 1, 0);
		else {
			sdoku(x, y + 1);
		}
		return;
	}
		
	
	for (int k = 1; k <= 9; k++) {
		if (!col[x][k] && !row[y][k] && !box[x / 3][y / 3][k]) {
			col[x][k] = true;
			row[y][k] = true;
			box[x / 3][y / 3][k] = true;
			arr[x][y] = k;
			if (y == 8)
				sdoku(x + 1, 0);
			else {
				sdoku(x, y + 1);
			}
			arr[x][y] = 0;
			col[x][k] = false;
			row[y][k] = false;
			box[x / 3][y / 3][k] = false;
		}
	}


}
void sol() {
	init();
	sdoku(0,0);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < 9; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 9; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	sol();

	
}