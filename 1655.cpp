#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;


int n, num[100001], temp1, temp2;
priority_queue<int> pq_left;
priority_queue<int,vector<int>,greater<int>> pq_right;
bool rl = false;
int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			pq_right.push(num[i]);
			rl = true;
		}
		else {
			pq_left.push(num[i]);
			rl = false;
		}
		if (pq_right.empty() != true && pq_left.empty() != true) {
			if (pq_right.top() < pq_left.top()) {
				temp1 = pq_left.top();
				temp2 = pq_right.top();
				pq_left.pop();
				pq_right.pop();
				pq_left.push(temp2);
				pq_right.push(temp1);
			}
		}
		if (rl) {
			cout << pq_right.top()<<"\n";
		}
		else {
			cout << pq_left.top()<<"\n";
		}
	}
	
}