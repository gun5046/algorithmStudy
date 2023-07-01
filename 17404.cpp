#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 99999999;
using namespace std;


int n;
int arr[1000][3];
int dp[1000][3][3];
int first;
void sol(int idx, int color) {
	
	if (idx == n) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (color == i) continue;
		if (idx == n - 1) {
			if (i == first) continue;
		}
		if (dp[idx][i][first] > dp[idx - 1][color][first] + arr[idx][i]) {
			dp[idx][i][first] = dp[idx - 1][color][first] + arr[idx][i];
			sol(idx + 1, i);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = arr[0][0];
	dp[0][1][1] = arr[0][1];
	dp[0][2][2] = arr[0][2];
	first = 0;
	sol(1,0);
	first = 1;
	sol(1, 1);
	
	first = 2;
	sol(1, 2);
	int mini=INF;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (dp[n - 1][i][j] < mini)
				mini = dp[n - 1][i][j];
		}
	}
	cout << mini;
}
