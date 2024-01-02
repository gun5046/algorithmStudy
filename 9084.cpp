#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

int t;

void makeCoin(vector<int>coins, int target) {
	
	
}

int main() {

	cin >> t;

	for (int test = 0; test < t; test++) {
		int n;
		cin >> n;
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		int money;
		cin >> money;

		makeCoin(v, money);
	}
}