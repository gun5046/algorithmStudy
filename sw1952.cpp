#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#define INF 99999999;

using namespace std;
int test;
int cost[4];
int plan[13];
int sum[13];
void swimming(int prev, int idx) {
	if (idx > 12) {
		return;
	}

		if (plan[idx] * cost[0] + sum[prev] < sum[idx]) {
			sum[idx] = plan[idx] * cost[0] + sum[prev];
		}
		if (cost[1] + sum[prev] < sum[idx]) {
			sum[idx] = sum[prev] + cost[1];
		}

		int idx2 = min(12, idx + 2);
		if (cost[2] + sum[prev] < sum[idx2]) {
			sum[idx2] = sum[prev] + cost[2];
		}
		swimming(idx, idx + 1);
}

void sol() {
	sum[12] = cost[3];
	swimming(0,1);
}

int main() {
	cin >> test;
	for (int t = 1; t <= test; t++) {
	
		for (int i = 0; i < 4; i++) {
			cin >> cost[i];
		}
		for (int i = 1; i < 13; i++) {
			cin >> plan[i];
			sum[i] = INF;
		}
		sum[0] = 0;
		sol();
		cout <<"#"<<t<<" "<<sum[12]<<"\n";
	}
}