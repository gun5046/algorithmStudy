#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int n;
int arr[3000][3000];
int cnt[3];
void sol(int x1, int y1, int x2, int y2) {
	bool flag = false;

	int a = arr[x1][y1];
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (arr[i][j] != a) {
				flag = true;
				break;
			}
		}
	}
	//cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";

	int nx = x1 + (x2-x1)/3 ;
	int ny = y1 + (y2-y1) / 3;
	int nnx = nx + (x2 - x1) / 3;
	int nny = ny + (y2 - y1) / 3;
		if (flag) {
		sol(x1, y1, nx, ny);
		sol(x1, ny, nx, nny);
		sol(x1, nny, nx, y2);

		sol(nx, y1, nnx, ny);
		sol(nx, ny, nnx, nny);
		sol(nx, nny, nnx, y2);

		sol(nnx, y1, x2, ny);
		sol(nnx, ny, x2, nny);
		sol(nnx, nny, x2, y2);

	}
	else {
		if (a == -1) {
			cnt[2]++;
		}
		else {
			cnt[a]++;
		}
	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	sol(0,0,n,n);

	cout << cnt[2] << endl << cnt[0] << endl << cnt[1];
}