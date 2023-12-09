#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n, m, s;

int arr[401][401];
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		arr[n1][n2] = -1;
		arr[n2][n1] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1) {
					arr[i][j] = 1;
					arr[j][i] = -1;
				}
				else if (arr[i][k] == -1 && arr[k][j] == -1) {
					arr[i][j] = -1;
					arr[j][i] = 1;
				}
			}
		}
	}
	cin >> s;
	vector<pair<int, int>>v;
	for (int c = 0; c < s; c++) {
		int n1, n2;
		cin >> n1 >> n2;
		v.push_back({ n1,n2 });
	}

	for (pair<int, int> p : v) {
		if (arr[p.first][p.second] == 0 || arr[p.second][p.first] == 0) {
			cout << 0 << "\n";
		}
		else {
			cout << arr[p.first][p.second] << "\n";
		}
	}
}
