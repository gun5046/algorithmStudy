#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;


vector<int>v;
int val = 2000000000;
pair<int, int> res;
void sol(int front, int back) {
	if (front == back) {
		return;
	}
	int temp = v[back] + v[front];
	if (abs(val) > abs(temp)) {
		val = temp;
		res = { front, back };
	}
	if (temp > 0) {
		sol(front, back - 1);
	}
	else if (temp < 0) {
		sol(front + 1, back);
	}
	else {
		return;
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int front = 0, back = n - 1;

	sol(front, back);

	cout << v[res.first] << " " << v[res.second];
}