#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int r, c, t;
int arr[50][50][2];
bool f;
pair<int, int>cleaner;

int main() {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0;j < c; j++) {
			cin >> arr[i][j][0];
			if (arr[i][j][0] == -1) {
				cleaner = { i,j };
			}
			else if (arr[i][j][0] != 0) {
				
			}
		}
	}
}