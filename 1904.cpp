#include <iostream>
#include <vector>
#define MOD 15746
using namespace std;

int n;
//1 1 하나도 못쓸때  1
//2 11 00 하나 쓸때   2
//3 111 100 001   dp[0]+dp[1]   3
//4 1111 1100 0011 0000 1001   5
//5 11111 11100 00111 11001 10011 00001 00100 10000  8
//6 111111 111100 111001 110011 100111 001111 110000 001100 100001 000011 100100 001001 000000  13
int dp[1000001];

void sol(int m) {

	for (int i = 3; i <= m; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= MOD;
	}

}

int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	sol(n);

	cout << dp[n];
}