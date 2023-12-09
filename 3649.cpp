#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>

using namespace std;

int x;
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (cin >> x) {
		x *= 10000000;
		cin >> n;
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		int start = 0;
		int end = v.size() - 1;
		while (end>start) {
			if (v[end] + v[start] == x) {
				cout << "yes " << v[start] << " " << v[end]<<"\n";
				break;
			}
			else if (v[end] + v[start] < x) {
				start++;
			}
			else {
				end--;
			}
		}
		if (end <= start) {
			cout << "danger"<<"\n";
		}

	}

	return 0;
}