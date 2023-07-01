#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;


priority_queue<int, vector<int>, greater<int>>pq;
queue<int>q;
int n,c,a;

int main() {
	
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		pq.push(c);
	}


	while (!pq.empty()) {
		a = pq.top();
		pq.pop();
		if (pq.empty()) {
			break;
		}
		a += pq.top();
		sum += a;
		pq.pop();
		if (pq.empty()) {
			break;
		}
		pq.push(a);
	}
	cout << sum;
}