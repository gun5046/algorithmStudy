#include <iostream>
#include <queue>
#define NE -1
#include <cstring>
using namespace std;
int n, k, w;
priority_queue<int>q;
int maximum=0;
int weight[101];
int value[101];
int dp[100001] = { NE };

void bag() {

	for (int i = 1; i <= n; i++){
		if (weight[i] <= k) {
			for (int j = k - weight[i]; j >= 1; j--) {
				if (dp[j] != NE) {
					if (dp[weight[i] + j] <= value[i] + dp[j]) {
						dp[weight[i] + j] = value[i] + dp[j];
						if (maximum <= dp[weight[i] + j]) {
							maximum = dp[weight[i] + j];
						}
					}

				}
			}
			if (dp[weight[i]] <= value[i]) {
				dp[weight[i]] = value[i];
				if (maximum <= dp[weight[i]]) {
					maximum = dp[weight[i]];
				}
			}
		}
	}
}

int main() {

	memset(dp, -1, sizeof(dp));
	cin >> n>> k;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	bag();


	cout << maximum;
}

