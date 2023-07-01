#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <utility>
using namespace std;
priority_queue<int>pq;
pair<int, int> arr[10];
int n;
void solution(int x, int a, int b) {
	
	for (int i = x; i < n; i++) {
		int a1 = a * arr[i].first;
		int b1 = b + arr[i].second;
		pq.push(-abs(a1 - b1));
		solution(i + 1, a1, b1);
	}
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	solution(0, 1, 0);
	cout << -pq.top();
}