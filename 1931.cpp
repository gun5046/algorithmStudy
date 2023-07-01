#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int arr[24];
vector<pair<int, int>>v;

void meeting(int start, int end, int c) {

}
int main() {
	cin >> n;


	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ e, s });
	}

	sort(v.begin(), v.end());
	int cnt = 1;
	int end = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= end) {
			cnt++;
			end = v[i].first;
		}
	}

	cout << cnt;
}