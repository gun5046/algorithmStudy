#include <iostream>

using namespace std;

int arr[9][9];
bool box[2][9][10];
bool box1[3][3][10];
bool f;
void sdoku(int x, int y) {
	if (f) return;
	if (x >8) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		f = true;
		return;
	}
	
	if (arr[x][y] != 0) {
		if (y < 8) {
			sdoku(x, y + 1);
		}
		else {
			sdoku(x + 1, 0);
		}
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (!box[0][x][i] && !box[1][y][i] && !box1[x / 3][y / 3][i]) {
				box[0][x][i] = true;
				box[1][y][i] = true;
				box1[x / 3][y / 3][i] = true;
				arr[x][y] = i;
				//cout << x << " " << y << " " << i << "추가" << "\n";
				if (y < 8) {
					sdoku(x, y + 1);
				}
				else {
					sdoku(x + 1, 0);
				}
				//cout << x << " " << y << " " << i << "삭제" << "\n";
				arr[x][y] = 0;
				box[0][x][i] = false;
				box[1][y][i] = false;
				box1[x / 3][y / 3][i] = false;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			
			if (arr[i][j] != 0) {
				box[0][i][arr[i][j]] = true;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[j][i] != 0) {
				box[1][i][arr[j][i]] = true;
			}
		}
	}
	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j += 3) {
			for (int n = i; n < i + 3; n++) {
				for (int m = j; m < j + 3; m++) {
					if (arr[n][m] != 0)
						box1[i/3][j/3][arr[n][m]] = true;
				}
			}
		}
	}

	sdoku(0,0);

}

/*
0 0 0 0 0 0 0 0 0
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
0 0 0 0 0 0 0 0 0
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 3 8 4
6 4 3 7 8 1 9 5 2
0 0 0 0 0 0 0 0 0
*/
/*
0 4 0 0 0 0 2 0 0

0 6 0 0 0 5 0 0 0

2 0 5 0 8 0 0 0 7

0 0 6 0 0 0 0 0 0

5 0 7 0 0 1 9 0 0

0 0 0 0 4 0 0 1 0

0 0 0 3 0 0 0 0 8

0 2 0 0 0 0 0 0 0

9 0 1 0 0 4 7 0 0  

////////////////////////
1 4 8 9 7 3 2 6 5
7 6 9 4 2 5 3 8 1
2 3 5 1 8 6 4 9 7
4 1 6 2 5 9 8 7 3
5 8 7 6 3 1 9 2 4
3 9 2 7 4 8 5 1 6
6 7 4 3 9 2 1 5 8
8 2 3 5 1 7 6 4 9
9 5 1 8 6 4 7 3 2
*/