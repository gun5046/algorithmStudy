#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define INF  99999999
using namespace std;
vector<int>v[501];
int main() {
	int n, m;

	cin >> n >> m;
	bool arr[501][501];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = false;
		}
	}
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		arr[n1][n2] = true;
	}

	
	for (int k = 1; k <= n; k++) {
		arr[k][k] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!arr[i][k] || !arr[k][j]) continue;
				arr[i][j] = true;
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		bool check = true;
		for (int j = 1; j <= n; j++) {
			if (!arr[i][j]) {
				if (arr[j][i]) continue;
				check = false;
				break;
			}
		}
		if (check) {
			result++;
		}
	}
	cout << result;
}