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
int n;
vector<int>v1;
bool find(int num, int start, int end) {
	if (end - start <= 1) {
		if (v1[start] == num || v1[end] == num) {
			return true;
		}
		return false;
	}
	int mid = (end + start) / 2;
	if (v1[mid] < num) {
		return find(num, mid, end);
	}
	else if (v1[mid] == num) {
		return true;
	}
	else {
		return find(num, start, mid);
	}
}
int main() {
	int num;
	cin >> n;
	
	vector<bool>ans;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v1.push_back(num);
	}

	sort(v1.begin(),v1.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		ans.push_back(find(num, 0, n-1));
	}
	for (bool a : ans) {
		cout << a << "\n";
	}
}