#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#define INF 10000000000
using namespace std;

pair<int,int> v[500];

long long dp[500][500];
bool check[500][500];
int n;
long long multi(int start, int end) {
	if (check[start][end]) {
		return dp[start][end];
	}
	dp[start][end] = INF;
	if (end - start==1) {
		return dp[start][end] = v[start].first * v[start].second * v[end].second;
	}
	if (end == start) {
		return 0;
	}
	

	for (int i = start; i < end; i++) { // 1  ~ 3
		if (check[start][end]) continue;
		dp[start][end] = min(multi(start, i) + multi(i + 1, end) + v[start].first * v[i].second * v[end].second, dp[start][end]);
	}
	check[start][end] = true;
	
	return dp[start][end];
	
	
}

void sol() {
	
	
	memset(check, 0, sizeof(check));
	multi(0, n-1);

	cout << dp[0][n-1];
}
	
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		v[i] = { r,c };
	}

	sol();
}