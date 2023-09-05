#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <set>
#include <stack>
#include <queue>
using namespace std;
vector<int>v;
priority_queue<int>pq;

int main() {
	int n;
	int k;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	
	for (int i = 1; i < n; i++) {
		pq.push(v[i] - v[i - 1]);
	}
	int total = v[n - 1] - v[0];
	int sum = 0;
	for (int i = 0; i < k-1; i++) {
		if (!pq.empty()) {
			total -= pq.top();
			pq.pop();
		}
		else {
			cout << 0;
			return 0;
		}
	}

	cout << total;
	return 0;
}