#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <sstream>
#include <cstring>
#include <string>
#include <set>
#include <stack>

using namespace std;
vector<pair<int ,int>>v;
bool compare(pair<int ,int > p1, pair<int,int> p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

priority_queue<int>pq;
int cnt = 0;
int main() {
	int n, num1, num2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num1;
		cin >> num2;
		v.push_back({ num1, num2 });
	}

	sort(v.begin(), v.end(), compare);
	//for (int i = 0; i < v.size(); i++) {
		//cout << v[i].first << " " << v[i].second << "\n";
	//}
	
	for (int i = 0; i < n; i++) {
		while (!pq.empty()) {
			if (v[i].first >= -pq.top()) {
				pq.pop();
			}
			else {
				break;
			}
		}
		pq.push(-v[i].second);
		int a = pq.size();
		cnt = max(a, cnt);
	}

	cout << cnt;

}