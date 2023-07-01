#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


int n, k;
vector<int>v;
int big;
void sol(long long   front, long long  end) {
	int c = 0;
	int idx = 0;

	if (front+1>=end) {
		for (int i = k - 1; i >= 0; i--) {
			c += (v[i] / end);
		}
		if (c >= n) {
			cout << end;
		}
		else {
			cout << front;
		}
		return;
	}
	
	long long mid = (front + end) / 2;

	for (int i = k - 1; i >= 0; i--) {
		
		c += (v[i] / mid);
		
	}
	if (c >= n) {
		sol(mid, end);
	}
	else {
		sol(front, mid);
	}
	
}

int main() {
	cin >> k >> n;
	int num;
	for (int i = 0; i < k; i++) {
		cin >> num;
		
		v.push_back(num);
	}
	sort(v.begin(), v.end());


	sol(1, v[k-1]);
	
	return 0;
}