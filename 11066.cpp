#include <iostream>
#include <math.h>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

using namespace std;
vector<int>v;
int dp[501][501];
vector<int> sum;
bool check[501][501];
int mergeFile(int start, int end) {
	if (check[start][end]) return dp[start][end];
	if (start == end) {
		return 0;
	}
	
	for (int i = start; i < end; i++) {
		dp[start][end] = min(dp[start][end], mergeFile(start, i) + mergeFile(i + 1, end) + sum[end] - sum[start-1]);
	}
	check[start][end] = true;

	return dp[start][end];
}

// 40 30 30 20 
 
int main() {
	int test = 0;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		int k = 0;
		cin >> k;
		sum.clear();
		v.clear();
		v.push_back(0);
		sum.push_back(0);
		for (int i = 0; i < k; i++) {
			int num;
			cin >> num;
			v.push_back(num);
			sum.push_back(sum[i] + num);
		}
		
		cout << mergeFile(1, k) <<"\n";
	}
}