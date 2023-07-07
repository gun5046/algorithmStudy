#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <time.h>
#define INF 99999999
using namespace std;


int n;
int arr[100000];
stack<pair<int, int>>s;
int cnt[100000];
int close[100000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		close[i] = INF;
	}

	for (int i = 0; i < n; i++) {
		
		while (!s.empty() && s.top().first <= arr[i]) {
			s.pop();
		}
		cnt[i] += s.size();
		if (!s.empty()) {
			close[i] = s.top().second;
		}

		s.push({ arr[i],i });
	}

	while (!s.empty()) s.pop();
	
	for (int i = n-1; i >= 0; i--) {

		while (!s.empty() && s.top().first <= arr[i]) {
			s.pop();
		}
		cnt[i] += s.size();
		if (!s.empty()) {
			if (close[i] != INF) {
				if (abs(s.top().second - i) < abs(i - close[i])) {
					close[i] = s.top().second;
				}
				else if (abs(s.top().second - i) == abs(i - close[i])) {

				}
			}
			
			else {
				close[i] = s.top().second;
			}
		}

		s.push({ arr[i],i });
	}

	for (int i = 0; i < n; i++) {
		if (cnt[i] != 0) {
			cout << cnt[i] << " " << close[i] + 1 << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	}
}










