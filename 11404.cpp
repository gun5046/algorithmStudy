#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#define INF 99999999
using namespace std;

int n,m;
vector<pair<int, int>>v[101];
int arr[101][101];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] > c) {
			arr[a][b] = c;
		}
	}
	

	/*for (int k = 1; k <= n; k++) {
		arr[k][k] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}*/

	for (int k = 1; k <= n; k++) {
		arr[k][k] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <=n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF) cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}