#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, h;
int arr[31][11];
priority_queue<int>pq;
int cnt = 0;

void move(int start, int row, int col, int cnt) {
	if (cnt == 4) {
		return;
	}

	if (col == h+1) {
		if (start != row) return;
		if (start == n) {
			pq.push(-cnt);
		}
		else {
			move(start + 1, start + 1, 1, cnt);
		}
	}
	
	
	if (row - 1 >= 1 && row+1<=n) {
		if (arr[col][row] == 0) {
			if (arr[col][row-1] == 0 && arr[col][row+1] == 0) {
				arr[col][row - 1] = 1;
				arr[col][row] = -1;
				move(row - 1, col + 1, cnt+1);
				arr[col][row - 1] = 0;
				arr[col][row] = 0;
				
				arr[col][row + 1] = -1;
				arr[col][row] = 1;
				move(row + 1, col + 1, cnt+1);
				arr[col][row + 1] = 0;
				arr[col][row] = 0;
			}
			else if (arr[col][row - 1] == 0 && arr[col][row + 1] !=0) {
				arr[col][row - 1] = 1;
				arr[col][row] = -1;
				move(row - 1, col + 1, cnt + 1);
				arr[col][row - 1] = 0;
				arr[col][row] = 0;
			}
			else if (arr[col][row - 1] != 0 && arr[col][row + 1] ==0) {
				arr[col][row + 1] = -1;
				arr[col][row] = 1;
				move(row + 1, col + 1, cnt + 1);
				arr[col][row + 1] = 0;
				arr[col][row] = 0;

			}
			move(row, col + 1, cnt);
		}
		else {
			move(row + arr[col][row], col + 1, cnt);
		}
	
	}
	else if (row - 1 >= 1) {
		if (arr[col][row] == 0) {
			if (arr[col][row - 1] == 0) {
				arr[col][row - 1] = 1;
				arr[col][row] = -1;
				move(row - 1, col + 1, cnt + 1);
				arr[col][row - 1] = 0;
				arr[col][row] = 0;
			}
			move(row, col + 1, cnt);
		}
		else {
			move(row + arr[col][row], col + 1, cnt);
		}
	}
	else {
		if (arr[col][row] == 0) {
			if (arr[col][row + 1] == 0) {
				arr[col][row + 1] = -1;
				arr[col][row] = 1;
				move(row + 1, col + 1, cnt + 1);
				arr[col][row + 1] = 0;
				arr[col][row] = 0;
			}
			move(row, col + 1, cnt);
		}
		else {
			move(row + arr[col][row], col + 1, cnt);
		}
	}

}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		arr[n1][n2] = 1;
		arr[n1][n2 + 1] = -1;
	}

	move(1, 1, 1, 0);

	if (!pq.empty()) {
		cout << -pq.top();
	}
	else {
		cout << -1;
	}
}