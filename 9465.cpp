#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <math.h>
using namespace std;

int n;
int box[2][100001];
int dp[2][100001];

void sticker();
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j =0; j <= 1; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> box[j][k];
			}
		}
		memset(dp,0,sizeof(dp));

		box[0][0] = 0;
		box[1][0] = 0;
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = box[0][1];
		dp[1][1] = box[1][1];

		sticker();
	}

}

void sticker() {
	for (int i = 2; i <= n; i++) {
		dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + box[0][i];
		dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + box[1][i];
	}
	
	cout << max(dp[0][n], dp[1][n]) << "\n";
	
}