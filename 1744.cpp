#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <queue>
using namespace std;

int n, num;
int sum = 0;
priority_queue<int>pq;
priority_queue<int, vector<int>, greater<int>>minus_pq;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num <= 0) {
			minus_pq.push(num);
		}
		else {
			pq.push(num);
		}
	}
	int ms = minus_pq.size();
	int s = pq.size();
	if ((ms % 2) == 1) {
		for (int i = 0; i < ms / 2; i++) {
			int a = minus_pq.top();
			minus_pq.pop();
			int b = minus_pq.top();
			minus_pq.pop();
			sum += (a * b);
		}
		sum += minus_pq.top();
	}
	else {
		for (int i = 0; i < ms / 2; i++) {
			int a = minus_pq.top();
			minus_pq.pop();
			int b = minus_pq.top();
			minus_pq.pop();
			
			sum += (a * b);
			
		}
	}

	for (int i = 0; i < s/2; i++) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		if (a + b < a * b) {
			sum += (a * b);
		}
		else {
			sum += (a + b);
		}
	}
	if (!pq.empty()) {
		sum += pq.top();
	}
	// 모두양수일때/ 음수or0 하나가 남을때/ 음수나 0이 2개/ 가장작은 음수끼리 곱은 커질수 있다

	cout << sum;
}