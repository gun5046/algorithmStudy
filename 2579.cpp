#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int stairs[301];
int dp[301][2];
int stair_num;

priority_queue<int> pq;

void upStair(int n, int c,int score);
int main() {
	cin >> stair_num;
	for (int i = 1; i <= stair_num; i++) {
		cin >> stairs[i];
	}	
	memset(dp, -1, sizeof(dp));
	upStair(1,1, stairs[1]);
	upStair(2, 1, stairs[2]);
	if (dp[stair_num][0] > dp[stair_num][1]) cout << dp[stair_num][0];
	else {
		cout << dp[stair_num][1];
	}
}

void upStair(int n, int c, int score) {
	if (score < dp[n][c-1]) {
		return;
	}
	if (n > stair_num) return;
	dp[n][c-1] = score;
	
	int next_s1 = n + 1;
	int next_s2 = n + 2;
	if (c == 1) {
		upStair(next_s1, 2, score + stairs[next_s1]);
	}
	upStair(next_s2, 1, score + stairs[next_s2]);

}