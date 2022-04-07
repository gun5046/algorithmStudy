#include <iostream>
#include <vector>

using namespace std;
int n;
int k;
int dp[201][201];
int main() {
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[1][i]=1;
	}
	
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][j-k];
				dp[i][j] %= 1000000000;
			}
		}
	}
	cout << dp[k][n];
}