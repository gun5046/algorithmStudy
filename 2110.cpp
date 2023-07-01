#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#define INF 9999999999;
using namespace std;

int n;
int c;
vector<int>v;

int res = 0;
void share(int start, int end) {
	int cnt = 1;
	int temp = v[0];
	
	if (start + 1 >= end) {
		for (int i = 0; i < n; i++) {
			if (v[i] - temp >= end) {
				cnt++;
				temp = v[i];
			}
		}
		if (cnt >= c) {
			cout << end;
		}
		else {
			cout << start;
		}
		return;
	}

	int mid = (end + start)/2;

	for (int i = 0; i < n; i++) {
		if (v[i] - temp >= mid) {
			cnt++;
			temp = v[i];
		}
	}

	if (cnt >= c) {
		share(mid, end);
	}
	else {
		share(start, mid);
	}
}


int main() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	
	share(1, v[n-1]-v[0]);
}