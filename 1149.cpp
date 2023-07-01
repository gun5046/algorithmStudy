#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 999999999
using namespace std;

int n;
int arr[1000][3];
int dp[1000][3];
void sol(int m, int col) {
	if (m == n - 1) {
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (i == col) continue;
		if (dp[m][col] + arr[m + 1][i] < dp[m + 1][i]) {
			dp[m + 1][i] = dp[m][col] + arr[m + 1][i];
			sol(m + 1, i);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			dp[i][j] = INF;
		}
	}
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	
	for (int i = 0; i < 3; i++) {
		sol(0, i);
	}

	cout << min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });



}