#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;


int n;
int arr[128][128];
int cnt[2];
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
	int x_mid = (x1+x2)/2;
	int y_mid = (y1 + y2) / 2;
	if (flag) {
		sol(x1, y1, x_mid, y_mid);
		sol(x1, y_mid, x_mid, y2);
		sol(x_mid, y1, x2, y_mid);
		sol(x_mid, y_mid, x2, y2);
	}
	else {
		cnt[a]++;
	}

}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	sol(0,0, n,n);

	cout << cnt[0] << "\n" << cnt[1];
}